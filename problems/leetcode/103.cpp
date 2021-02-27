# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool state = true;
        vector<vector<int>> res;
        queue<TreeNode*> BFS;
        BFS.push(root);
        size_t BFS_size;
        while (BFS_size = BFS.size()) {
            vector<int> temp;
            for (size_t i = 0; i < BFS_size; ++i) {
                if (state) {
                    temp.push_back(BFS.top)
                }
            }
        }
    }
};