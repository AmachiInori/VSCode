#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int Alength = 0, Blength = 0;
        ListNode *str = headA;
        while(str) {
            str = str -> next;
            Alength++;
        }
        str = headB;
        while(str) {
            str = str -> next;
            Blength++;
        }
        if (Alength > Blength) {
            for (int i = 0; i < Alength - Blength; i++)
                headA = headA -> next;
        }else if (Alength < Blength) {
            for (int i = 0; i < Blength - Alength; i++)
                headB = headB -> next;
        }
        while (headA && headB){
            if (headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};