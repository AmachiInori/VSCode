#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode(0), *str = newHead;
        newHead -> next = head;
        while (str && str -> next) {
            if (str -> next -> val == val) str -> next = str -> next -> next;
            else str = str -> next; //实现连续删除
        }
        return newHead -> next;
    }
};