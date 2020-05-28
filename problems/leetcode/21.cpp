/*
 * @Author: your name
 * @Date: 2020-04-21 17:40:31
 * @LastEditTime: 2020-04-21 18:00:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\21.cpp
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* str = res;
        while (l1 != NULL || l2 != NULL){
            if ((l1 != NULL && l2 != NULL && l2 -> val >= l1 -> val) || l1 != NULL && l2 == NULL){
                ListNode* temp = new ListNode(l1 -> val);
                str -> next = temp;
                str = str -> next;
                l1 = l1 -> next;
            }else {
                ListNode* temp = new ListNode(l2 -> val);
                str -> next = temp;
                str = str -> next;
                l2 = l2 -> next;
            }
        }
        return res -> next;
    }
};