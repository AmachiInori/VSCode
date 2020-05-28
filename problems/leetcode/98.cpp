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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        LDR(root);
        for (int i = 0; i < LDRRes.size() - 1; i++)
            if (LDRRes[i] >= LDRRes[i + 1]) return false;
        return true;
    }
};