/*
 * @Author: your name
 * @Date: 2020-04-20 13:25:42
 * @LastEditTime: 2020-04-20 13:39:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\20.cpp
 */
#include <iostream>
#include <string>
using std::string;

template<typename type>
class listNode
{ 
public:
    type data;
    listNode *next;

    listNode()
    {
        data = 0;
        next = NULL;
    }
    listNode(type data_, listNode *str)
    {
        data = data_;
        next = str;
    }
    bool friend operator==(listNode &a, listNode &b)
    {
        if(a.data == b.data && a.next == b.next) return true;
        else return false;
    }
    ~listNode(){}
};

template<typename type>
class list_stack
{
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

template<typename type>
list_stack<type>::list_stack()
{
    listNode<type> *str = new listNode<type>;
    length = 0;
    head = str;
}

template<typename type>
list_stack<type>::~list_stack()
{
    listNode<type> *str = makeEmpty();
    delete str;
}

template<typename type>
void list_stack<type>::push(type value)
{
    listNode<type> *str = new listNode<type>;
    str -> data = value;
    str -> next = head -> next;
    head -> next = str;
    length++;
}

template<typename type>
type list_stack<type>::pop()
{
    listNode<type> *str = head -> next;
    type value = str -> data;
    head -> next = str -> next;
    delete str;
    length--;
    return value;
}

template<typename type>
listNode<type> *list_stack<type>::makeEmpty()
{
    while (head -> next != NULL)
        pop();
    return head;
}

template<typename type>
type list_stack<type>::top()
{
    if (head -> next == NULL) return 0;
    else return head -> next -> data;
}

class Solution {
public:
    bool isValid(string s) {
    list_stack<char> stack;
    char temp;
    int isError = 0;

    for (int i = 0; i < s.size(); i++)
    {
        temp = s[i];
        if (temp == '{' || temp == '[' || temp == '(')
            stack.push(temp);
        else if (temp == '}' || temp == ']' || temp == ')')
        {
            char theTop = stack.top();
            if (temp == '}' && theTop == '{')
                stack.pop();
            else if (temp == ')' && theTop == '(')
                stack.pop();
            else if (temp == ']' && theTop == '[')
                stack.pop();
            else
                return false;
        }
    }
        if (stack.getlength() != 0) return false;
        else return true;
    }

};