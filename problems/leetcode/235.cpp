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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        TreeNode* str = root;
        while(true) {
            pathP.emplace_back(str);
            if (p -> val > str -> val) str = str -> right;
            else if (p -> val < str -> val) str = str -> left;
            else break;
        }
        str = root;
        while(true) {
            pathQ.emplace_back(str);
            if (q -> val > str -> val) str = str -> right;
            else if (q -> val < str -> val) str = str -> left;
            else break;
        }
        int loca = pathP.size() > pathQ.size() ? pathQ.size() : pathP.size();
        loca -= 1;
        for (int i = loca; i >= 0; i--){
            if (pathP[i] == pathQ[i]) return pathP[i];
        }
        return NULL;
    }
};