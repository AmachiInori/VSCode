#ifndef _HUFF_DECODE_H
#define _HUFF_DECODE_H

#include <map>
#include <fstream>
#include <cstdint>

#include "huffman.h"
#include "huffTree.h"

namespace huffman {

    class huffDecode {
    private:
        fileHead* _fileHead;
        huffmanTree* _htree;
        std::map<uchar, int> _freq_table;
        std::map<uchar, std::string> _code_table;
        std::map<std::string, uchar> _decodeMap;
    public:
        huffDecode() : _fileHead(nullptr), _htree(nullptr) {
            _fileHead = new fileHead();
        }
        ~huffDecode() {
            if (!_fileHead) delete _fileHead;
            if (!_htree) delete _htree;
        }
    private:
        static bool _isLeaf(huffmanTreeNode* n) {
            return n -> m_left == nullptr && n -> m_right == nullptr;
        }
        long _getFileSize(const char* strFileName) {
            std::ifstream in(strFileName);
            if (!in.is_open()) return 0;

            in.seekg(0, std::ios_base::end);
            std::streampos sp = in.tellg();
            in.close();
            return sp;
        }
        bool _calc_freq_table(const char* filename) {
            std::ifstream is(filename, std::ios::binary);
            if (!is) {
                printf("read file failed! filename: %s", filename);
                return false;
            }

            is.read((char*)_fileHead, sizeof(fileHead));
            if (!(_fileHead->flag[0] == 'h' &&
                _fileHead->flag[1] == 'a' &&
                _fileHead->flag[2] == 'r' &&
                _fileHead->flag[3] == 'c')) {
                printf("not support this file format! filename: %s\n", filename);
                return false;
            }

            /*for (int i = 0; i < static_cast<int>(_fileHead->alphaVariety); ++i) {
            struct table {uint8_t ch[256];} t;
            is.read((char*)&t, sizeof(table));
            }
            _htree = new huffmanTree(t.ch);
            */
            std::

            is.close();
            return true;
        }
        bool _decode(const char* srcFilename,
            const char* destFilename) {
            long fileSize = _getFileSize(srcFilename);

            std::ifstream is(srcFilename, std::ios::binary);
            if (!is) {
                printf("read file failed! filename: %s", srcFilename);
                return false;
            }
            is.seekg(sizeof(fileHead) + sizeof(uint8_t) *256);

            huffmanTreeNode node = _htree->getHuffTree();
            huffmanTreeNode* pNode = &node;

            std::ofstream io(destFilename, std::ios::binary);
            if (!io) {
                printf("create file failed! filename: %s", destFilename);
                return false;
            }

            uchar value;
            std::string code;
            int index = 0;
            long curLocation = is.tellg();
            is.read((char*)&value, sizeof(uchar));
            while (1) {
                if (_isLeaf(pNode)) {
                    uchar ch = _decodeMap[code];
                    io.write((char*)&ch, sizeof(uchar));
                    if (curLocation >= fileSize && index >= _fileHead->lastValidBit) {
                        break;
                    }
                    code.clear();
                    pNode = &node;
                }

                if (GET_BYTE(value, index)) {
                    code += '1';
                    pNode = pNode->m_right;
                }
                else {
                    pNode = pNode->m_left;
                    code += '0';
                }
                if (++index >= 8) {
                    index = 0;
                    is.read((char*)&value, sizeof(uchar));
                    curLocation = is.tellg();
                }
            }

            is.close();
            io.close();
            return true;
        }
    public:
        bool decode(const char* srcFilename, const char* destFilename) {
            if (!_calc_freq_table(srcFilename)) return false;
            long fileSize = _getFileSize(srcFilename);
            //_htree = new huffmanTree(_freq_table);
            _htree->huffmanCode(_code_table);

            for (auto it : _code_table) {
                _decodeMap.insert(std::pair<std::string, uchar>(it.second, it.first));
            }

            return _decode(srcFilename, destFilename); // 有个更好的方式：直接在树上操作。遇1向右，遇0向左，isleaf(now)就返回now->m_data,now=root,循环
                                                       // 而不是在这里用字符串
        }
    
    };

}

#endif

