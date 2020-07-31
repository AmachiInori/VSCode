#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        bool res = true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1)
            return false;
        res = res && isBalanced(root->left) && isBalanced(root->right);
        return res;
    }
};