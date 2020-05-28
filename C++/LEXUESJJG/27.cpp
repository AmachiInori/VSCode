#include <iostream>

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
    listNode<type> *makeEmpty();
    void printAll();
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
void list_stack<type>::printAll() //不够漂亮
{
    listNode<type> *str = head -> next;
    while (str != NULL)
    {
        std::cout << str -> data << ' ';
        str = str -> next;
    }
    std::cout << std::endl;
}

int main()
{
    list_stack<int> low, mid, high;
    int number, temp, *str;
    std::cin >> number;
    str = new int[number];
    for (int i = 0; i < number; i++)
    {
        std::cin >> str[i];
    }
    
    for (int i = 0; i < number; i++)
    {
        temp = str[number - 1 - i];
        if (temp < 60)
            low.push(temp);
        else if (temp >= 60 && temp < 100)
            mid.push(temp);
        else if (temp >= 100)
            high.push(temp);
    }
    std::cout << "60>x:";
    low.printAll();
    std::cout << "60<=x<100:";
    mid.printAll();
    std::cout << "x>=100:";
    high.printAll();

    temp = system("pause");
    return 0;
}