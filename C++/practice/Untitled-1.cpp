#include <bits/stdc++.h>
using namespace std;

struct Student
{
    unsigned int age;
    char sex;
    string name;
    int num;
};

Student lihua = { 17,'m',"lihua" };
Student wangwu = { 16,'f' ,"wangwu" };
Student zhangsan = {16 ,'f' ,"zhangsan" };
//Student classone[3] = { lihua,wangwu,zhangsan };
Student *classone[3] = { &lihua,&wangwu,&zhangsan };
Student *pclassone = *classone;
//数组在如注释中定义的时候 只是分配了3个空间，然后把lihua，wangwu，zhangsan的参数复制进来，其他数组例如int数组或者char数组也一样，所有数组定义时如果用{实例名}的方法定义，都只进行值复制。
//因此classone[0]和lihua的各项参数虽然都是一样的，但他们的地址不同。
//因此指针pclassone只能指向数组，不能进一步指向lihua，wangwu，zhangsan这三个实例。
//如20行的改动，利用指针嵌套可以实现pclassone->classone->lihua（如上的定义pclassone会自动指向classone[0]）

void setnum(Student* a);

int main()
{
    ++pclassone->num = 1001;
    int idx;
    for (idx = 0; idx <= 2; ++idx)
    {
        setnum(pclassone);
        ++pclassone;
    }
    cout << lihua.num << ' ' << wangwu.num << ' ' << zhangsan.num << endl;
    cout << classone[0]->num << ' ' << (*classone[0]).num << endl;
}

void setnum(Student* a)
{
    static int x = 1000;
    a->num =x++ ;

}
