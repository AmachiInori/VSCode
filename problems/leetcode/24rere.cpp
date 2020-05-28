#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*> temp;
        int count = 0;
        ListNode* str, *tempS = head, *res, *begin;
        str = new ListNode(0);
        str -> next = NULL;
        res = str;
        while (1) {
            if (count == 2) {
                while (!temp.empty()) {
                    str -> next = temp.top();
                    temp.pop();
                    str = str -> next;
                }
                begin = str -> next;
                str -> next = NULL;
                count = 0;
            }
            else {
                if (!tempS) break;
                ListNode *temptemp = tempS;
                tempS = tempS -> next;
                temp.push(temptemp);
                count++;
            }
        }
        stack<ListNode*> newStack;
        while (!temp.empty()) {
            newStack.push(temp.top());
            temp.pop();
        }
        while (!newStack.empty()) {
            str -> next = newStack.top();
            newStack.pop();
            str = str -> next;
            str -> next = NULL;
        }
        return res -> next;
    }
};