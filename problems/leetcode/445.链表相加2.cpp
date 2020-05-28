/*
 * @Author: your name
 * @Date: 2020-04-19 10:53:30
 * @LastEditTime: 2020-04-19 11:51:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\445.链表相加2.cpp
 */


//https://leetcode-cn.com/problems/add-two-numbers-ii/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *str = res;
        ListNode *temp1 = l1, *temp2 = l2;
        int length1 = 0, length2 = 0;
        int isFirstAdded = 0;
        while(temp1||temp2){
            if(temp1){
                temp1 = temp1 -> next;
                length1++;
            }
            if(temp2){
                temp2 = temp2 -> next;
                length2++;
            }
        }
        const int resultLength = length1 > length2 ? length1 : length2;
        ListNode** index = new ListNode*[resultLength];
        index[0] = res;
        
        temp1 = l1, temp2 = l2;
        for (int i = 0; temp1||temp2; i++)
        {
            int tempNumber = 0;
            if (length1 > length2){
                tempNumber = temp1 -> val;
                length1--;
                temp1 = temp1 -> next;
            }else if (length1 < length2){
                tempNumber = temp2 -> val;
                length2--;
                temp2 = temp2 -> next;
            }else {
                tempNumber = temp1 -> val + temp2 -> val;
                length1--, length2--;
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            
            ListNode *tempStr = new ListNode(tempNumber);
            str -> next = tempStr;
            if(str -> next) str = str -> next;
            if((i + 1) < resultLength) index[i + 1] = tempStr;
        }

        for (int i = 1; i <= resultLength; i++){
            if (i != 1) str = index[resultLength - i + 1];
            if (str -> val >= 10) {
                index[resultLength - i] -> val++;
                str -> val -= 10;
            }
        }
        
        if (res -> val > 0) return res;
        else return res -> next;
    }
};