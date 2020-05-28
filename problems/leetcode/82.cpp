#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead -> next = head;
        ListNode* nowLoca = newHead;
        while (nowLoca && nowLoca -> next && nowLoca -> next -> next) {
            if (nowLoca -> next -> val != nowLoca -> next -> next -> val) nowLoca = nowLoca -> next;
            else {
                ListNode* temp = nowLoca -> next;
                while (temp && temp -> val == nowLoca -> next -> val) temp = temp -> next;
                nowLoca -> next = temp;
            }
        }
        return newHead -> next;
    }
};