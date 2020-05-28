#include <iostream>
#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> index;
        while (head){
            index.push_back(head);
            head = head -> next;
            for (int i = 0; i < index.size(); i++)
                if (index[i] == head) return true;
        }
        return false;
    }
};