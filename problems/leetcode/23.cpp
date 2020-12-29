#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> heap;
        for_each(lists.begin(), lists.end(), [&heap](ListNode* temp) {
            while (temp) {
                heap.push(temp->val);
                temp = temp->next;
            }
        });
        if (heap.empty()) return nullptr;
        ListNode* res = new ListNode(heap.top());
        heap.pop();
        while (!heap.empty()) {
            ListNode* temp = new ListNode(heap.top());
            temp->next = res;
            res = temp;
            heap.pop();
        }
        return res;
    }
};