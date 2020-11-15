#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> list_stack;
        ListNode* cur = head;
        while (cur != nullptr) {
            list_stack.push(cur);
            cur = cur->next;
        }
        if (list_stack.size() <= 2) return;
        cur = head;
        size_t length = list_stack.size();
        for (size_t i = 0; i <= (length - 1) / 2; i++) {
            ListNode* nxt = cur->next;
            ListNode* end = list_stack.top();
            list_stack.pop();
            list_stack.top()->next = nullptr;
            cur->next = end;
            end->next = nxt;
            cur = nxt;
        }
    }
};