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
    vector<int> path;
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        int isTrue = 1;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] > root -> val) isTrue = 0;
        }
        res += isTrue;
        path.push_back(root -> val);
        res += goodNodes(root -> left) + goodNodes(root -> right);
        path.pop_back();
        return res;
    }
};