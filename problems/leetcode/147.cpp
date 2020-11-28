#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    typedef ListNode* iterator;
public:
    ListNode* insertionSortList(ListNode* head) {
        iterator current = head, sorted = head;
        while (current != nullptr) {
            iterator ist_loca;
            for (ist_loca = head; ist_loca != sorted && current->val < ist_loca->val; ist_loca = ist_loca->next);

        }
    }
};