#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* getRight(TreeNode* root) {
        while (root && root->right)
            root = root->right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode *preN = root, *nowN;
        while (preN != nullptr) {
            while (preN != nullptr && preN->left == nullptr)
                preN = preN->right;
            if (preN == nullptr)
                return;
            nowN = preN->left;
            TreeNode *tempPtN = getRight(nowN);
            tempPtN->right = preN->right;
            preN->right = nowN;
            preN->left = nullptr;
        }
    }
};