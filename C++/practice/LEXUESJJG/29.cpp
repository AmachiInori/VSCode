/*
 * @Author: your name
 * @Date: 2020-04-19 12:08:55
 * @LastEditTime: 2020-04-19 12:16:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\C++\LEXUESJJG\29.cpp
 */

#include <iostream>
#include <assert.h>

template<typename type>
class listNode
{
public:
    type data;
    listNode<type> *next;

    listNode()
    {
        data = 0;
        next = NULL;
    }

    bool friend operator==(listNode &a, listNode &b)
    {
        if(a.data == b.data && a.next == b.next) return true;
        else return false;
    }
};

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
    listQueue<int> odd, even;
    int number;
    std::cin >> number;
    for (int i = 0; i < number; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp - (temp / 2) * 2) odd.enQueue(temp);
        else even.enQueue(temp);
    }
    while (even.getSize() && odd.getSize())
        std::cout << odd.deQueue() << ' ' << even.deQueue() << std::endl;
    
    system("pause");
    return 0;
}