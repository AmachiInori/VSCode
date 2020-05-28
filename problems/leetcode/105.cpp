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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int location;
        if(inorder.empty() || preorder.empty()) return NULL;
        TreeNode* res = new TreeNode(preorder.front());
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == preorder.front()) {
                location = i;
                break;
            }
        }
        vector<int> leftPre(&preorder[1], &preorder[location + 1]);
        vector<int> rightPre(&preorder[location + 1], &preorder[preorder.size()]);
        vector<int> leftIn(&inorder.front(), &inorder[location]);
        vector<int> rightIn(&inorder[location + 1], &inorder[inorder.size()]);
        res -> left = buildTree(leftPre, leftIn);
        res -> right = buildTree(rightPre, rightIn);
        return res;
    }
};