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
    ListNode* swapPairs(ListNode* head) {
        if (!head -> next) return head;
        ListNode* res = head -> next;
        ListNode* str = head;
        ListNode* temp = NULL;
        while (str) {
            if (temp) {
                ListNode* ttemp = str -> next;
                str -> next = temp;
                str = str -> next;
                str -> next = ttemp;
                temp = NULL;
            } else {
                temp = str;
            }
            str = str -> next;
        }
        if (temp) str -> next = temp;
        return res;
    }
};