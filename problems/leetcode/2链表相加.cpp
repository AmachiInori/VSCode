/*
 * @Author: your name
 * @Date: 2020-04-19 10:20:07
 * @LastEditTime: 2020-04-19 10:45:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\2链表相加.cpp
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//https://leetcode-cn.com/problems/add-two-numbers/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode *str1 = l1, *str2 = l2;
        ListNode *res = new ListNode(0), *resStr;
        resStr = res;
        while (l1||l2||add){
            int temp = add;
            add = 0;
            if (l1){
                temp += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2){
                temp += l2 -> val;
                l2 = l2 -> next;
            }
            if (temp >= 10){
                temp -= 10;
                add = 1;
            }
            ListNode *tempStr = new ListNode(temp);
            resStr -> next = tempStr;
            resStr = resStr -> next;
        }
        return res -> next;
    }
};