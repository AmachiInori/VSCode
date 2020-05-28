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
        ListNode* str = head;
        ListNode* lastLoca;
        while (str) {
            lastLoca = str;
            if (!(str && str -> val == lastLoca -> val)) str = str -> next;
            else while (str && str -> val == lastLoca -> val)
                str = str -> next;
            lastLoca -> next = str;
        }
        return head;
    }
};