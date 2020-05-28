/*
 * @Author: your name
 * @Date: 2020-04-19 12:22:31
 * @LastEditTime: 2020-04-19 12:45:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\C++\LEXUESJJG\30.cpp
 */

//链表栈0.11 2020.4.14
//0.11新增了top()函数以返回顶值但不弹出
#include <iostream>
#include <assert.h>

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

    int push(type value);
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
int list_stack<type>::push(type value)
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

template<typename type>
class listQueue
{
protected:
    listNode<type> *head;//出位置，指向存在的节点
    listNode<type> *rear;//入位置，指向存在的节点而不是next
    int size;
public:
    listQueue();
    ~listQueue(){};

    int getSize(){return size;}
    int enQueue(type value);
    type deQueue();
    type getFront(){return head -> next -> data;};
    type getRear(){return rear -> data;};
    void makeEmpty();
};

template<typename type>
listQueue<type>::listQueue()
{
    head = new listNode<type>;
    rear = head;
    head -> next = NULL;
    size = 0;
}

template<typename type>
int listQueue<type>::enQueue(type value)
{
    listNode<type> *str = new listNode<type>;
    str -> data = value;
//  str -> next = NULL;
    rear -> next = str;
    rear = str;
    size++;
}

template<typename type>
type listQueue<type>::deQueue()
{
    assert(size);
    type temp = head -> next -> data;
    listNode<type> *str = head -> next;
    head -> next = head -> next -> next;
    size--;
    delete str;
    return temp;
}

template<typename type>
void listQueue<type>::makeEmpty()
{
    rear = head;
    listNode<type> *str = head;
    while (str -> next != NULL)
    {
        listNode<type> *temp = str;
        str = str -> next;
        delete temp;
    }
    size = 0;
}

int main()
{
    list_stack<char> theStack;
    listQueue<char> theQueue;
    bool res = true;
    char temp;
    while ((temp = std::cin.get()) != '\n')
    {
        theStack.push(temp);
        theQueue.enQueue(temp);
    }
    const int length = theQueue.getSize();
    for (int i = 0; i < length; i++)
    {
        if (theStack.pop() != theQueue.deQueue())
        {
            res = false;
            break;
        }
    }

    if (res) std::cout << "是回文" << std::endl;
    else std::cout << "不是回文" << std::endl;

    system("pause");
    return 0;
}