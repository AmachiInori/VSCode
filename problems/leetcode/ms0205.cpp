#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using std::vector;
using std::stack;
using std::string;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = l1;
        if (!l1) return l2;
        if (!l2) return l1;
        while (true) {
            l1 -> val = l1 -> val + l2 -> val;
            if (!(l1 -> next && l2 -> next)) break;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (l2 -> next) l1 -> next = l2 -> next;
        l1 = start;
        while (l1 -> next) {
            if (l1 -> val >= 10) {
                l1 -> next -> val++; 
                l1 -> val -= 10;
            }
            l1 = l1 -> next;
        }
        if (l1 -> val >= 10) {
            ListNode* temp = new ListNode(1);
            l1 -> next = temp;
            l1 -> val -= 10;
        }
        return start;
    }
};