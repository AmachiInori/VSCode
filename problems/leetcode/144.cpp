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
    vector<int> DLRRes;
    void DLR(TreeNode* str) {
        if (str) {
            DLRRes.push_back(str -> val);
            DLR(str -> left);
            DLR(str -> right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        DLR(root);
        return DLRRes;
    }
};