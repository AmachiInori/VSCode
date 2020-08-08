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
    int lastValue = INT_MIN;
    TreeNode* biggerWrong = nullptr;
    TreeNode* smallerWrong = nullptr;
    TreeNode* lastPtN;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        this->inorder(root->left);
        if (root->val < lastValue) {
            if (biggerWrong == nullptr) biggerWrong = lastPtN;
            smallerWrong = root;
        }
        lastValue = root->val;
        lastPtN = root;
        this->inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (biggerWrong == nullptr) return;
        int tempInt = biggerWrong->val;
        biggerWrong->val = smallerWrong->val;
        smallerWrong->val = tempInt;
        return;
    }
};