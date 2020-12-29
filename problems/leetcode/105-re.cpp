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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if(inorder.empty() || preorder.empty()) return nullptr;
        TreeNode* res = new TreeNode(preorder.front());
        unsigned int location = 
            find_first_of(inorder.begin(), inorder.end(), preorder.begin(), preorder.begin() + 1) - 
            inorder.begin();
        vector<int> leftPre(&preorder[1], &preorder[location + 1]);
        vector<int> rightPre(&preorder[location + 1], &preorder[preorder.size()]);
        vector<int> leftIn(&inorder.front(), &inorder[location]);
        vector<int> rightIn(&inorder[location + 1], &inorder[inorder.size()]);
        res -> left = buildTree(vector<int>(&preorder[1], &preorder[location + 1]), 
                                vector<int>(&*inorder.begin(), &inorder[location]));
        res -> right = buildTree(rightPre, rightIn);
        return res;
    }
};