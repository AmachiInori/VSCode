#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> inOrder;
public:
    void inOrderRunner(TreeNode* root) {
        if (!root) {
            inOrder.push_back(INT_MIN);
            return;
        }
        if (!(root -> left || root -> right)) {
            inOrder.push_back(root -> val);
            return;
        }
        inOrderRunner(root -> left);
        inOrder.push_back(root -> val);
        inOrderRunner(root -> right);
    }
    bool isSymmetric(TreeNode* root) {
        inOrderRunner(root);
        for (int i = 0; i < inOrder.size() / 2; i++)
            if (inOrder[i] != inOrder[inOrder.size() - 1 - i]) return false;
        return true;
    }
};