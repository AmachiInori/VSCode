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
    int getSingleSum(TreeNode* root) {
        int res = 0;
        if (root -> left) {
            if (root -> left -> left) res += root -> left -> left -> val;
            if (root -> left -> right) res += root -> left -> right -> val;
        }
        if (root -> right) {
            if (root -> right -> left) res += root -> right -> left -> val;
            if (root -> right -> right) res += root -> right -> right -> val;
        }
        return res;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        if (!(root -> val % 2)) res += getSingleSum(root);
        res += sumEvenGrandparent(root -> left) + sumEvenGrandparent(root -> right);
        return res;
    }
};