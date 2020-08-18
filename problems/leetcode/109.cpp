#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* maketree(vector<int>& number) {
        if (number.empty()) return nullptr;
        int middle = number.size() / 2;
        vector<int> left(&number[0], &number[middle]);
        vector<int> right(&number[middle + 1], &number[number.size()]);
        TreeNode* tempPtN = new TreeNode(number[middle], maketree(left), maketree(right));
        return tempPtN;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> number;
        while (head != nullptr) {
            number.push_back(head->val);
            head = head->next;
        }
        return maketree(number);
    }
};