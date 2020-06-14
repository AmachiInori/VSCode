#ifndef _HUFF_TREE_H
#define _HUFF_TREE_H

#include <cstdint>
#include <map>
#include <queue>
#include <string>

namespace huffman {
    struct huffmanTreeNode {
        uint8_t m_data;
        int m_freq;
        huffmanTreeNode* m_left;
        huffmanTreeNode* m_right;

        huffmanTreeNode (uint8_t da, int freq, huffmanTreeNode* l = nullptr, huffmanTreeNode* r = nullptr) :
            m_data(da), m_freq(freq), m_left(l), m_right(r) {}
        bool operator< (const huffmanTreeNode& node) const { // overload for p_queue
            if (m_freq == node.m_freq) return m_data > node.m_data;
            return m_freq > node.m_freq;
        }
        void operator= (const huffmanTreeNode& n) { 
            m_data = n.m_data;
            m_freq = n.m_freq;
            m_left = n.m_left;
            m_right = n.m_right;
        }
    };

    class huffmanTree {
    private:
        std::priority_queue<huffmanTreeNode> que;
        std::map<uint8_t, std::string> code_table;

    public:
        huffmanTree(const std::map<uint8_t, int>& freq_map) {
            for (auto && [key, val] : freq_map) { // cxx11+
                huffmanTreeNode n(key, val);
                que.push(n); // push in to priority_queue, instead of using std::sort
            }
            makehuffTree();
        }
        huffmanTree(const uint8_t ch[]) {
            int cnt = 0;
            while (cnt < 256) {
                huffmanTreeNode n(ch[cnt], 256 - cnt); // 利用线性表可以存霍夫曼树的性质，只要256个不同的uint8_t就能重建树
                que.push(n);
                cnt++;
            }
            makehuffTree();
        }
        ~huffmanTree() {
            huffmanTreeNode node = que.top();
            _delete_tree(&node);
        }
        void makehuffTree() {
            while (que.size() > 1) {
                huffmanTreeNode* left = new huffmanTreeNode(que.top());
                std::cout << que.top().m_data << ' ';
                que.pop();
                huffmanTreeNode* right = new huffmanTreeNode(que.top());
                std::cout << que.top().m_data << ' ';
                que.pop();
                huffmanTreeNode* node = new huffmanTreeNode('0', left -> m_freq + right -> m_freq, left, right);
                que.push(*node);
            }
        }
        void huffmanCode(std::map<uint8_t, std::string>& code_table) {
            huffmanTreeNode node = que.top();
            std::string code;
            _huffmanCode(&node, code, code_table);
        }
        const huffmanTreeNode &getHuffTree() { return que.top(); }

    private:
        bool _isLeaf(huffmanTreeNode* n) { return n->m_left == nullptr && n->m_right == nullptr; }

        void _delete_tree(huffmanTreeNode* n) {
            if (!n)
                return;
            _delete_tree(n -> m_left);
            _delete_tree(n -> m_right);
            //delete n;
        }

        void _huffmanCode(huffmanTreeNode* root, std::string& code,
            std::map<uint8_t, std::string>& code_table) {
            if (_isLeaf(root)) { //允许串中只有一种字符的情况了，该情况下定义编码只有一位0
                code = '0';
                code_table[root -> m_data] = code;
            }
            if (root -> m_left != nullptr) {
                std::string tmp = code;
                tmp += '0';
                if (_isLeaf(root -> m_left)) {
                    code_table[root -> m_left -> m_data] = tmp;
                }
                else {
                    _huffmanCode(root -> m_left, tmp, code_table);
                }
            }
            if (root -> m_right != nullptr) {
                std::string tmp = code;
                tmp += '1';
                if (_isLeaf(root -> m_right)) {
                    code_table[root -> m_right -> m_data] = tmp;
                }
                else {
                    _huffmanCode(root -> m_right, tmp, code_table);
                }
            }
        }
    };
} // namespace huffman

#endif