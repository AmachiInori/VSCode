#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p = nullptr, *q = head, *r = q -> next;
        while(q) {
            q -> next = p;
            p = q;
            q = r;
            if (r) r = r -> next;
        }
        return p;
    }
};