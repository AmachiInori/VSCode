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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int length = 0;
        ListNode* str = head;
        while (str) {
            str = str -> next;
            length++;
        }
        str = head;
        for (int i = 0; i < length - k; i++)
            str = str -> next;
        return str;
    }
};