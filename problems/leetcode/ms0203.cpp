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
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
        return;
    }
};