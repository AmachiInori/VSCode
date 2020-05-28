/*
 * @Author: your name
 * @Date: 2020-04-23 20:56:52
 * @LastEditTime: 2020-04-24 12:21:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\32.cpp
 */
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

template<typename type>
class listNode{
public:
    type data;
    listNode *next;

    listNode(){
        data = 0;
        next = NULL;
    }
    listNode(type data_, listNode *str){
        data = data_;
        next = str;
    }
    bool friend operator==(listNode &a, listNode &b){
        if(a.data == b.data && a.next == b.next) return true;
        else return false;
    }
};

template<typename type>
class list_stack{
protected:
    listNode<type> *head;
    int length;
public:
    list_stack();
    ~list_stack();

    void push(type value);
    type pop();
    type top();
    listNode<type> *makeEmpty();
    int getlength(){return length;}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> str = vector(s.length(), -1);
        list_stack<int> stack;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(') stack.push(i);
            if (s[i] == ')' && stack.getlength()){
                str[i] = 1;
                str[stack.pop()] = 1;
            }
        }
        vector<int> index = vector(s.length() + 2, -1);
        bool isWholeTrue = true;
        int pointer = 1;
        for (int i = 0; i < str.size(); i++){
            if (str[i] == -1){
                isWholeTrue = false;
                index[pointer++] = i;
            }
        }
        index[pointer] = s.length();

        if (isWholeTrue) return s.length();
        else {
            int max = -1;
            for (int i = 0; i < s.length() + 1; i++){
                int temp = index[i + 1] - index[i] - 1;
                if (temp > max) max = temp;
            }
            return max;
        }
    }
};

template<typename type>
list_stack<type>::list_stack(){
    listNode<type> *str = new listNode<type>;
    length = 0;
    head = str;
}

template<typename type>
list_stack<type>::~list_stack(){
    listNode<type> *str = makeEmpty();
    delete str;
}

template<typename type>
void list_stack<type>::push(type value){
    listNode<type> *str = new listNode<type>;
    str -> data = value;
    str -> next = head -> next;
    head -> next = str;
    length++;
}

template<typename type>
type list_stack<type>::pop(){
    listNode<type> *str = head -> next;
    type value = str -> data;
    head -> next = str -> next;
    delete str;
    length--;
    return value;
}

template<typename type>
listNode<type> *list_stack<type>::makeEmpty(){
    while (head -> next != NULL)
        pop();
    return head;
}

template<typename type>
type list_stack<type>::top(){
    if (head -> next == NULL) return 0;
    else return head -> next -> data;
}