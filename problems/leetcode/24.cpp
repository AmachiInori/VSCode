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
        int length = 0;
        ListNode* strT = head;
        while (strT) {
            length++;
            strT = strT -> next;
        }
        vector<ListNode*> index(length, NULL);
        int point = 0;
        ListNode* res = new ListNode(0);
        ListNode* str = res;
        while (head) {
            index[point] = head;
            head = head -> next;
            point++;
        }
        for (int i = 0; i < index.size(); i++) {
            if (i % 2) {
                str -> next = index[i];
                str = index[i];
                str -> next = index[i - 1];
                str = index[i - 1];
            }
            if (i == index.size() - 1 && !(i % 2)) {
                str -> next = index[i];
            }
        }
        return res -> next;
    }
};//?????