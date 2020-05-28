//链表队列 2020.4.13
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

/************************************/

int main() //test
{
    int temp, length;
    std::cin >> length;
    listQueue<int> test;
    for (int i = 0; i < length; i++)
    {
        std::cin >> temp;
        test.enQueue(temp);
    }
    for (int i = 0; i < length - length / 2; i++)
    {
        std::cout << test.deQueue() << std::endl;
    }
    for (int i = 0; i < length / 2; i++)
    {
        std::cin >> temp;
        test.enQueue(temp);
    }
    for (int i = 0; i < length; i++)
    {
        std::cout << test.deQueue() << std::endl;
    }

    system("pause");
    return 0;
}