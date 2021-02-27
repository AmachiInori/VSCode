#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!(head && head->next)) return head;
        ListNode* current_next = head, *current;
        while (current_next && current_next->val < x) {
            current = current_next;
            current_next = current_next->next;
        }
        if (!current) current = head;
        ListNode* cursor = current_next, *cursor_before;
        while (cursor) {
            while (cursor && cursor->val >= x) {
                cursor_before = cursor;
                cursor = cursor->next;
            }
            if (!cursor) break;
            ListNode* curr_next = cursor->next;
            cursor->next = current->next;
            current->next = cursor;
            cursor_before->next = curr_next;
            current = current->next;
            cursor = curr_next;
        }
        return head;
    }
};