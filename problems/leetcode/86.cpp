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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(0), *biggerHead = new ListNode(0);
        ListNode* strS = smallHead, *strB = biggerHead;
        while (head) {
            if (head -> val >= x) {
                ListNode* temp = new ListNode(head -> val);
                strB -> next = temp;
                strB = strB -> next;
            } else {
                ListNode* temp = new ListNode(head -> val);
                strS -> next = temp;
                strS = strS -> next;
            }
            head = head -> next;
        }
        strS -> next = biggerHead -> next;
        return smallHead -> next;
    }
};