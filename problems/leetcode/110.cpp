#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getDepth(TreeNode* root, int depth) {
        if (!root) return depth;
        return max(getDepth(root -> left, depth + 1), getDepth(root -> right, depth + 1));
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        if (!root) return res;
        res = isBalanced(root -> left) && isBalanced(root -> right);
        if (abs(getDepth(root -> left, 0) - getDepth(root -> right, 0)) > 1) res = false;
        return res;
    }
};