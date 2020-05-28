#include <iostream>
#include <vector>

using std::vector;

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
    bool res = false;
    bool isSametree(TreeNode* a, TreeNode* b) {
        if (!(a||b)) return true;
        else if (!a || !b || (a -> val != b -> val)) return false;
        else return isSametree(a -> left, b -> left) && isSametree(a -> right, b -> right);
    }
    void isSubtreeRunner(TreeNode* s,TreeNode* t){
        if (!s) return;
        if (isSametree(s, t)) res = true;
        else {
            isSubtreeRunner(s -> left, t);
            isSubtreeRunner(s -> right, t);
        }
        return;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        isSubtreeRunner(s, t);
        return res;
    }
};