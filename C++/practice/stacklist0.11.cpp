//链表栈0.11 2020.4.14
//0.11新增了top()函数以返回顶值但不弹出
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

/************************************/

int main()
{
    list_stack<int> stack;
    stack.makeEmpty();
    int temp;
    while (std::cin >> temp)
    {
        stack.push(temp);
        if (std::cin.get() == '\n')
            break;
    }
    while (stack.getlength() > 0)
    {
        std::cout << stack.pop() << std::endl;
    }

    system("pause");
    return 0;
}