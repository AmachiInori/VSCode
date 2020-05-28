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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp -> next;
            length++;
        }
        temp = head;
        for (int i = length - 1; i >= 0; i--){
            res += pow(2, i) * temp -> val;
            temp = temp -> next;
        }
        return res;
    }
};