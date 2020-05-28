//一般树，练习写的 没啥用
//2020.4.15
//带控制台的那种 控制台只支持int 可以拿出来继承写
#include <iostream>
#include <assert.h>
#include <string.h>

template <typename type>
class treeNode
{
public:
    type data;
    treeNode<type> *next;//下一个兄弟的地址
    treeNode<type> *down;//第一个儿子的地址
    treeNode<type> *pre;//前驱元地址

    treeNode(){};
    ~treeNode(){};
    bool friend operator==(treeNode<type> a, treeNode<type> b)
    {
        if (a.data == b.data && a.next == b.next && a.down == b.down)
            return true;
        else return false;
    }
};

template <typename type>
class tree
{
protected:
    treeNode<type> *root;//根位置，有值
    treeNode<type> *pointer; //操作位置
public:
    tree(type);
    ~tree(){};

    void addChild(type);//兼容有第一儿子的情况
    void addSibling(type);//保持原顺序，在尾部插入值
    void pointerPre(){pointer = pointer -> pre;}
    void pointerDown(){
        if(pointer -> down)
            pointer = pointer -> down;
    }
    void pointerRight(){
        if(pointer -> next);
            pointer = pointer -> next;
    }
    void pointerZero(){pointer = root;}
    void editData(type value){pointer -> data = value;}
    type printData(){return pointer -> data;}
    void deleteNodeRunner(treeNode<type>*);//删除节点的内核方法 别直接调用这个！！
    void deleteNode(){deleteNodeRunner(pointer);pointer = root;}//递归删除节点的驱动程序
    void printAllPre(){printAllPreRunner(root, 0);}//先序遍历
    void printAllPreRunner(treeNode<type> *str, int depth);//别用！
    void printAllPost(){printAllPostRunner(root, 0);}//后序遍历
    void printAllPostRunner(treeNode<type> *str, int depth);//别用！
    void console();
};
void printSpace(int n);

template <typename type>
tree<type>::tree(type value)
{
    root -> data = value;
    root -> next = NULL;
    root -> down = NULL;
    root -> pre = NULL;
}

template <typename type>
void tree<type>::addChild(type value)
{
    if (pointer -> down)
    {
        treeNode<type> *originPointer = pointer;
        pointerDown();
        addSibling(value);
        pointer = originPointer;
    }
    else
    {
        treeNode<type> *str = new treeNode<type>;
        str -> data = value;
        str -> pre = pointer;
        str -> next = NULL;
        str -> down = NULL;
        pointer -> down = str;
    }
}

template <typename type>
void tree<type>::addSibling(type value)
{
    treeNode<type> *originPointer = pointer;
    while (pointer -> next)
        pointerRight();
    treeNode<type> *str = new treeNode<type>;
    str -> data = value;
    str -> next = NULL;
    str -> down = NULL;
    str -> pre = pointer;
    pointer -> next = str;
    pointer = originPointer;
}

template <typename type>
void tree<type>::deleteNodeRunner(treeNode<type> *str)
{
    if (str == NULL) return;
    if (str -> next)
    {
        deleteNodeRunner(str -> next);
        str -> next = NULL;
    }
    if (str -> down)
    {
        deleteNodeRunner(str -> down);
        str -> down = NULL;
    }
    if (str != root)
    {   if (str -> pre -> next == str) str -> pre -> next = NULL;
        if (str -> pre -> down == str) str -> pre -> down = NULL;
        delete str;
    }
}

template <typename type>
void tree<type>::printAllPreRunner(treeNode<type> *str, int depth)
{
    if (!str) return;
    printSpace(depth);
    std::cout << depth << ':' << str -> data;
    if (pointer == str) std::cout << " <-";
    std::cout << std::endl;
    if (str -> down) printAllPreRunner(str -> down, depth + 1);
    if (str -> next) printAllPreRunner(str -> next, depth);
}

template <typename type>
void tree<type>::printAllPostRunner(treeNode<type> *str, int depth)
{
    if (!str) return;
    printAllPreRunner(str -> down, depth + 1);
    printSpace(depth);
    std::cout << depth << ':' << str -> data;
    if (pointer == str) std::cout << " <-";
    std::cout << std::endl;
    printAllPreRunner(str -> next, depth);
}

template <typename type>
void tree<type>::console()
{
    char operate = 0;
    int temp;
    while (true)
    {
        system("cls");
        printAllPre();
        operate = getchar();
        switch (operate)
        {
        case 'p':
            printAllPost();
            break;
        case 'e':
            scanf("%d", &temp);
            editData(temp);
            break;
        case 'u':
            pointerPre();
            break;
        case 'c':
            pointerDown();
            break;
        case 'r':
            pointerRight();
            break;
        case 'z':
            pointerZero();
            break;
        case 'd':
            deleteNode();
            break;
        case 'a':
            scanf("%d", &temp);
            addChild(temp);
            break;
        case 'n':
            scanf("%d", &temp);
            addSibling(temp);
            break;
        case 'o':
            return;
        }
    }
}

void printSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "     ";
    }
}

/******************************************/

int main()
{
    tree<int> testTree(0);
    int temp = 0, cont = 0;
    std::cin >> temp;
/*    while (temp != -1)
    {
        if (cont == 2)
        {
            testTree.addChild(temp);
            testTree.pointerDown();
            cont++;
        }
        else if (cont == 5)
        {
            testTree.pointerRight();
            testTree.addChild(temp);
            cont = 0;
        }
        else
        {
            testTree.addSibling(temp);
            cont++;
        }
        std::cin >> temp;
    }

    testTree.printAllPost();
    std::cout << "-------------" << std::endl;
    testTree.printAllPre();
    system("pause");
    */
    testTree.console();

    return 0;
}