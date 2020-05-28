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
class abslist
{
protected:
    listNode<type> *head;
    int length;
public:
    abslist();

    listNode<type> *getHead(){return head;};
    type getData(int i);
    listNode<type> *findPrevious(int i);
    listNode<type> *findPrevious(type val, int nu);
    int set(type x, int i);
    listNode<type> *findNumber(type val);
    listNode<type> *find(int i);
    void MakeEmpty();
    virtual listNode<type> *getNext(listNode<type> &n) = 0;
    virtual int insert(type value, int i) = 0;
    virtual int insert(type value) = 0;
    virtual int remove(int i) = 0;
};

template<typename type> 
abslist<type>::abslist()
{
    listNode<type> *str = new listNode<type>;
    head = str;
    length = 0;
}

template<typename type>
type abslist<type>::getData(int i)
{
    listNode<type> *str = find(i);
    assert(str != NULL && str != head);
    return str -> data;
}

template<typename type>
listNode<type> *abslist<type>::find(int i)
{
    listNode<type> *str = getHead();
    for (int j = 0; j < i && i <= length; j++)
        str = str -> next;
    return str;
}

template<typename type>
listNode<type> *abslist<type>::findPrevious(int i)
{
    assert(i <= length && i != 0);
    return find(i - 1);
}

template<typename type>
listNode<type> *abslist<type>::findPrevious(type value, int nu)
{
    listNode<type> *str = getHead();
    while (str -> next && str -> next -> data != value)
    {
        str = str -> next;
    }
    return str;
}

template<typename type>
int abslist<type>::set(type x, int i)
{
    listNode<type> *str = find(i);
    str -> data = x;
    return 0;
}

template<typename type>
listNode<type> *abslist<type>::findNumber(type val)
{
    listNode<type> *str = getHead();
    int i = 0;
    for (int i = 0; i < length; i++)
        if(str -> data == val) break;
        else str = str -> next;
    return str;
}

template<typename type>
void abslist<type>::MakeEmpty()
{
    listNode<type> *tempstr = getHead();
    for (int i = 0; i < length; i++)
    {
        listNode<type> *str = tempstr -> next;
        delete tempstr;
        tempstr = str;
    }
    length = 0;
    head -> next = NULL;
}

class intlist : public abslist<int>
{
public:
    listNode<int> *getNext(listNode<int> &n)override
    {
        listNode<int> *str = getHead();
        for (int i = 0; i < abslist::length; i++)
        {
            if (*str == n) return str;
            else str = str -> next;
        }
        return str;
    }

    int insert(int value, int i)override
    {
        listNode<int> *str = find(i);
        listNode<int> *strp = findPrevious(i);
        listNode<int> *newstr = new listNode<int>;
        newstr -> data = value;
        newstr -> next = str;
        strp -> next = newstr;
        length++;
        return 0;
    }

    int insert(int value)override
    {
        listNode<int> *str = head -> next;
        listNode<int> *newstr = new listNode<int>;
        newstr -> data = value;
        newstr -> next = str;
        head -> next = newstr;
        length++;
        return 0;
    }

    int remove(int i)override
    {
        listNode<int> *str = find(i);
        listNode<int> *pstr = findPrevious(i);
        pstr -> next = str -> next;
        delete str;
        length--;
        return 0;
    }

    int removePrevious(int value)
    {
        if(head -> next -> data == value) return 1;
        else
        {
            listNode<int> *str = findPrevious(value, 1);
            return removeNumber(str -> data);
        }
    }

    int removeNumber(int value)
    {
        listNode<int> *str = findNumber(value);
        listNode<int> *pstr = findPrevious(value, 1);
        pstr -> next = str -> next;
        delete str;
        length--;
        return 0;
    }

    int inserttail(int value)
    {
        if(length == 0 )
            insert(value);
        else
        {
            listNode<int> *str = getHead();
            while (str -> next != NULL)
            {
                str = str -> next;
            }
            listNode<int> *newstr = new listNode<int>;
            newstr -> data = value;
            newstr -> next = NULL;
            str -> next = newstr;
            length++;
        }
        return 0;
    }

    void print()
    {
        listNode<int> *str = getHead() -> next;
        if (length == 0)
        {
            std::cout << "没有交集" << std::endl;
            return;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                std::cout << str -> data << ' ';
                str = str -> next;
            }
            std::cout << std::endl;
        }
    }

    intlist friend jiaoji(intlist A, intlist B)
    {
        intlist result;
        result.MakeEmpty();
        listNode<int> *stra = A.getHead();
        listNode<int> *strb = B.getHead();
        for (stra = A.getHead() -> next; stra != NULL; stra = stra -> next)
        {
            for (strb = B.getHead() -> next; strb != NULL; strb = strb -> next)
            {
                if (stra -> data == strb -> data)
                {
                    result.inserttail(stra -> data);
                }
                else continue;
            }
        }
        return result;
    }
};

int main()
{
    intlist listA, listB;
    int temp;
    while (std::cin >> temp)
    {
        listA.inserttail(temp);
        if (std::cin.get() == '\n')
            break;
    }
    while (std::cin >> temp)
    {
        listB.inserttail(temp);
        if (std::cin.get() == '\n')
            break;
    }

    intlist result = jiaoji(listA, listB);
    result.print();

    system("pause");
    return 0;
}