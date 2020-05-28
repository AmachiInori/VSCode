#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    vector<ListNode*> index;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        while (head){
            index.push_back(head);
            head = head -> next;
        }
        if (index.size() - n != 0) {
            ListNode* str = index[index.size() - n - 1];
            ListNode* temp = str -> next;
            str -> next = temp -> next;
            delete temp;
            return index[0];
        }else {
            if (index.size() > 1) return index[1];
            else return NULL;
        }
    }
};