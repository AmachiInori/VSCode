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
private:
    vector<vector<int>> res;
    void DFS(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (res.size() <= depth) {
            res.push_back({});
        }
        res[depth].push_back(root->val);
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        DFS(root, 0);
        vector<int> realRes(res.size(), int(INT_MIN));
        for (int i = 0; i < realRes.size(); i++) {
            for (auto &j : res[i]) {
                if (j > realRes[i])
                    realRes[i] = j;
            }
        }
        return realRes;
    }
};