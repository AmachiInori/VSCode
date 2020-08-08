#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *res = new ListNode(0), *str = head, *strR = res;
        int count = 0;
        while (str != nullptr) {
            count++;
            if (count >= m && count <= n) {
                ListNode *temp = new ListNode(str->val);
                temp->next = strR->next;
                strR->next = temp;
                str = str->next;
            } else {
                while (strR->next != nullptr) strR = strR->next;
                ListNode *temp = new ListNode(str->val);
                temp->next = nullptr;
                strR->next = temp;
                strR = strR->next;
                str = str->next;
            }
        }
        return res->next;
    }
};