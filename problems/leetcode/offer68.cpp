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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> visited;
        TreeNode* current = root;
        while (current) {
            visited.insert(current);
            if (current->val > p->val) {
                current = current->left;
            } else if (current->val < p->val) {
                current = current->right;
            } else break;
        }
        current = root;
        TreeNode* res = nullptr;
        while (visited.find(current) != visited.end()) {
            res = current;
            if (current->val > q->val) {
                current = current->left;
            } else if (current->val < q->val) {
                current = current->right;
            } else break;
        }
        return res;
    }
};