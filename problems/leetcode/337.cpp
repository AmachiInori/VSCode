#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode *, int> hash;
    int _rob(TreeNode* root) {
        int res = root->val;
        if (root->left != nullptr)
            res += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr)
            res += rob(root->right->left) + rob(root->right->right);
        return res;
    }
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (hash.find(root) != hash.end())
            return hash[root];
        int get = _rob(root);
        int inget = rob(root->right) + rob(root->left);
        hash[root] = max(get, inget);
        return max(get, inget);
    }
};