#ifndef _HUFF_ENCODE_H
#define _HUFF_ENCODE_H

#include <cstdint>
#include <fstream>
#include <map>
#include <queue>

#include "huffTree.h"
#include "huffman.h"

namespace huffman {

    class huffEncode {
    private:
        std::map<uint8_t, int> _freq_table;
        std::map<uint8_t, std::string> _code_table;
    public:
        bool encode(const char* src, const char* dst) {
            if (!_calc_freq_table(src))
                return false;
            huffmanTree tree(_freq_table);
            tree.huffmanCode(_code_table);
            return _encode(src, dst);
        }

    private:
        int _calc_valid_bits_of_last_byte() {
            int sum = 0;
            for (auto& [key, val] : _code_table) {
                sum += val.size() * _freq_table.at(key);
                sum &= 0xFF;
            }
            sum &= 0x7;
            return sum == 0 ? 8 : sum;
        }
        bool _calc_freq_table(const char* filename) {
            uint8_t ch; 
            std::ifstream is(filename, std::ios::binary);
            if (!is.is_open()) {
                printf("read file failed! filename: %s", filename);
                return false;
            }
            is.read((char*)&ch, sizeof(uint8_t));
            while (!is.eof()) {
                _freq_table[ch]++;
                is.read((char*)&ch, sizeof(uint8_t));
            }

            std::string dictName(filename);
            dictName = dictName + ".dict";
            std::ofstream dictOut(dictName , std::ios::binary);
            

            is.close();
            /*
            for (auto &i : _freq_table) {
                std::cout << i.first << ' ' << i.second << std::endl;
            }
            */
            return true;
        }
        bool _encode(const char* src, const char* dst) {
            uint8_t ch;
            uint8_t value;
            int bit_index = 0;
            fileHead filehead = { 'h', 'a', 'r', 'c' };
            //filehead.alphaVariety = (uint8_t)_freq_table.size();
            filehead.lastValidBit = _calc_valid_bits_of_last_byte();

            std::ifstream is(src, std::ios::binary);
            if (!is.is_open()) { //重复判断？
                printf("read file failed! filename: %s", src);
                return false;
            }
            std::ofstream io(dst, std::ios::binary);
            if (!io.is_open()) {
                printf("read file failed! filename: %s", dst);
                return false;
            }

            io.write((char*)&filehead, sizeof(fileHead));
            /*for (auto i : _freq_table) {
                ch_freq cf(i);
                io.write((char*)&cf, sizeof(ch_freq));
            }*/
            std::priority_queue<ch_freq> q;
            for (auto i : _freq_table) {
                ch_freq cf(i);
                q.push(cf);
            }
            while (q.size()) {
                io.write((char*)&q.top().ch, sizeof(q.top().ch));
                q.pop();
            }

            is.read((char*)&ch, sizeof(uint8_t));
            while (!is.eof()) {
                std::string code = _code_table.at(ch);
                for (auto c : code) {
                    if ('0' == c) {
                        CLR_BYTE(value, bit_index);
                    }
                    else {
                        SET_BYTE(value, bit_index);
                    }
                    bit_index++;
                    if (bit_index >= 8) {
                        bit_index = 0;
                        io.write((char*)&value, sizeof(uint8_t));
                    }
                }
                is.read((char*)&ch, sizeof(uint8_t));
            }

            if (bit_index) {
                io.write((char*)&value, sizeof(uint8_t));
            }
            is.close();
            io.close();
            return true;
        }
    };
} // namespace huffman

#endif