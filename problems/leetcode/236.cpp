#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*> &theStack) {
        if (!root) return false;
        theStack.emplace_back(root);
        if (root == target) return true;
        if (find(root -> left, target, theStack)) return true;
        if (find(root -> right, target, theStack)) return true;
        theStack.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> stackP;
        vector<TreeNode*> stackQ;
        find(root, p, stackP), find(root, q, stackQ);
        int loca = stackP.size() > stackQ.size() ? stackQ.size() : stackP.size();
        loca -= 1;
        for (int i = loca; i >= 0; i--){
            if (stackP[i] == stackQ[i]) return stackP[i];
        }
        return NULL;
    }
};