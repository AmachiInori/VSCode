#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> hash;
public:
    int runner(TreeNode* root) {
        int res = root -> val;
        if (root -> left) res += runner(root -> left);
        if (root -> right) res += runner(root -> right);
        hash[res]++;
        return res;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        runner(root);
        vector<int> res;
        int max(0);
        for (auto &i : hash)
            if (i.second > max) max = i.second;
        for (auto &i : hash)
            if (i.second == max) res.push_back(i.first);
        return res;
    }
};