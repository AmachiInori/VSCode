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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> BFS;
        vector<int> out;
        if (root == nullptr)
            return {};
        BFS.push(root);
        int nowQueueSize = 0;
        while (nowQueueSize = BFS.size()) {
            for (int i = 0; i < nowQueueSize; i++) {
                out.push_back(BFS.front()->val);
                if (BFS.front()->left != nullptr) BFS.push(BFS.front()->left);
                if (BFS.front()->right != nullptr) BFS.push(BFS.front()->right);
                BFS.pop();
            }
        }
        return out;
    }
};