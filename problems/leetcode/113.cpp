#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> temp;
    vector<vector<int>> res;
public:
    void runner(TreeNode* str, int sum) {
        if (!str) return;
        if (sum == str -> val && !(str -> right || str -> left)) {
            temp.push_back(str -> val);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(str -> val);
        runner(str -> left, sum - str -> val);
        runner(str -> right, sum - str -> val);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        runner(root, sum);
        return res;
    }
};