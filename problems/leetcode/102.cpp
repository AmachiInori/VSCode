#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using std::vector;
using std::stack;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        runner(root, 0);
        return result;
    }
    void Insert(int val, int depth) {
        if (depth == result.size()) result.push_back({});
        result[depth].push_back(val);
    }
    void runner(TreeNode* root, int depth) {
        if (!root) return;
        Insert(root -> val, depth);
        if (root -> left) runner(root -> left, depth + 1);
        if (root -> right) runner(root -> right, depth + 1);
    }
};