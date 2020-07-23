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
public:
    vector<TreeNode*> generateTreesRunner(int start, int end) {
        if (start > end) return {nullptr};
        if (start == end) {
            TreeNode *tempPtN = new TreeNode(start);
            return {tempPtN};
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateTreesRunner(start, i - 1);
            vector<TreeNode*> right = generateTreesRunner(i + 1, end);
            for (auto &ptnA : left) {
                for (auto &ptnB : right) {
                    TreeNode *tempPtN = new TreeNode(i, ptnA, ptnB);
                    res.push_back(tempPtN);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesRunner(1, n);
    }
};