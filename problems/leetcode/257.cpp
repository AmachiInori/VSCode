#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int16_t> path;
    vector<string> res;
    void _binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (!(root->left || root->right)) {
            string temp;
            for (size_t i = 0; i < path.size() - 1; i++) {
                temp += to_string(path[i]);
                temp += string("->");
            }
            temp += to_string(path.back());
            res.push_back(temp);
            path.pop_back();
            return;
        }
        if (root->left) _binaryTreePaths(root->left);
        if (root->right) _binaryTreePaths(root->right);
        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        _binaryTreePaths(root);
        return res;
    }
};