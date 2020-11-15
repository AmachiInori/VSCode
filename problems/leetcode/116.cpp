#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> BFS;
        if (root == nullptr) return root;
        BFS.push(root);
        size_t width = 1;
        while (!BFS.empty()) {
            for (size_t i = 0; i < width; i++) {
                    if (BFS.front()->left) {
                    BFS.push(BFS.front()->left);
                    BFS.push(BFS.front()->right);
                }
                Node* current = BFS.front();
                BFS.pop();
                if (i == width - 1) current->next = nullptr;
                else current->next = BFS.front();
            }
            width <<= 1;
        }
        return root;
    }
};