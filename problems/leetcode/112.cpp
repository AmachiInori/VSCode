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
    bool isLeaf(TreeNode* s) { return !(s -> left || s -> right); }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (isLeaf(root)) return sum == root -> val;
        bool res = false;
        if (root -> left) res |= hasPathSum(root -> left, sum - root -> val);
        if (root -> right) res |= hasPathSum(root -> right, sum - root -> val);
        return res;
    }
};