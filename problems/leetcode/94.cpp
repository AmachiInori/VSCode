#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> LDRRes;
    void LDR(TreeNode* str) {
        if (str) {
            LDR(str -> left);
            LDRRes.push_back(str -> val);
            LDR(str -> right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        LDR(root);
        return LDRRes;
    }
};