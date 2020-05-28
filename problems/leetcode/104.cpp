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
    int max = INT_MIN;
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        runner(root, 1);
        return max;
    }
    void runner(TreeNode* root, int depth) {
        if (!(root -> left || root -> right)) {
            max = max > depth ? max : depth;
            return;
        }
        if (root -> left) runner(root -> left, depth + 1);
        if (root -> right) runner(root -> right, depth + 1);
    }
};