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
    vector<int> index = vector<int>(10, 0);
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        if (!root) return 0;
        index[root -> val]++;
        if (root -> left || root -> right) {
            res += pseudoPalindromicPaths(root -> left) + pseudoPalindromicPaths(root -> right);
        } else {
            res = 1;
            int jishu = 0;
            for (int i = 0; i < 9; i++){
                if (index[i] % 2) jishu++;
                if (jishu == 2){
                    res = 0;
                    break;
                }
            }
        }
        index[root -> val]--;
        return res;
    }
};