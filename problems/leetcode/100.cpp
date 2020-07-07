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
    bool isSameNode(TreeNode *p, TreeNode* q) {
        if ((p == nullptr) ^ (q == nullptr)) return false;
        if (p == nullptr) return true;
        return (p -> val == q -> val) && !(p -> left == nullptr ^ q -> left == nullptr) && !(p -> right == nullptr ^ q -> right == nullptr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!isSameNode(p, q)) return false;
        bool res = true;
        if (p && p -> left) res &= isSameTree(p -> left, q -> left);
        if (p && p -> right) res &= isSameTree(p -> right, q -> right);
        return res;
    }
};