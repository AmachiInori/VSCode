#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast) fast = fast->next;
            slow = slow->next;
            if (fast && fast == slow) return true;
        }
        return false;
    }
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast) {
        fast = fast->next;
        if (fast) fast = fast->next;
        slow = slow->next;
        if (fast && fast == slow) return true;
    }
    return false;
}