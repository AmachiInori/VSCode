//数组队列 2020.4.13
#include <iostream>
#include <assert.h>
#define modadd(x, v) (x + 1 - (x + 1) / v * v)//循环加法:(被加数，上限)

template<typename type> 
class queue
{
protected:
    type *str;//队列数组
    int front;//队头，弹的位置，指向实值
    int rear;//队尾，进的位置，指向空值
    int size;//目前大小
    int val;//容量
public:
    queue(int);
    ~queue();

    int enqueue(type);
    type dequeue();
    bool isEmpty(){return size == 0;};
    bool isFull(){return size == val;};
    void makeEmpty();
    type getFront(){return str[front];}
    type getRear(){return str[rear];}
};

template<typename type>
queue<type>::queue(int length)
{
    str = new type[length];     //没必要初始化
    front = 0;
    rear = 0;
    val = length;
    size = 0;
}

template<typename type>
queue<type>::~queue()
{
    delete str;
}

template<typename type>
int queue<type>::enqueue(type value)
{
    assert(!isFull());
    str[rear] = value;
    rear = modadd(rear, val);
    size++;
    return size;
}

template<typename type>
type queue<type>::dequeue()
{
    assert(!isEmpty());
    type temp = str[front];
    front = modadd(front, val);
    size--;
    return temp;
}

template<typename type>
void queue<type>::makeEmpty()
{
    front = 0;
    rear = 0;
    size = 0;
}

/************************************/

int main() //test
{
    int temp, length;
    std::cin >> length;
    queue<int> test(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> temp;
        test.enqueue(temp);
    }
    for (int i = 0; i < length - length / 2; i++)
    {
        std::cout << test.dequeue() << std::endl;
    }
    for (int i = 0; i < length / 2; i++)
    {
        std::cin >> temp;
        test.enqueue(temp);
    }
    for (int i = 0; i < length; i++)
    {
        std::cout << test.dequeue() << std::endl;
    }

    system("pause");
    return 0;
}