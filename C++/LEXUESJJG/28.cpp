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

int main()
{
    list_stack<char> stack;
    char temp;
    int isError = 0;

    while ((temp = std::cin.get()) != '\n')
    {
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
                isError = 1;
        }
    }
    if (stack.getlength() != 0) isError = 1;
    
//  std::cout << isError << ':' << stack.getlength() << std::endl;
    if (isError) std::cout << "括号不配对" << std::endl;
    else std::cout << "括号配对" << std::endl;

    system("pause");
    return 0;
}