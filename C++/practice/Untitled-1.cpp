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
//��������ע���ж����ʱ�� ֻ�Ƿ�����3���ռ䣬Ȼ���lihua��wangwu��zhangsan�Ĳ������ƽ�����������������int�������char����Ҳһ�����������鶨��ʱ�����{ʵ����}�ķ������壬��ֻ����ֵ���ơ�
//���classone[0]��lihua�ĸ��������Ȼ����һ���ģ������ǵĵ�ַ��ͬ��
//���ָ��pclassoneֻ��ָ�����飬���ܽ�һ��ָ��lihua��wangwu��zhangsan������ʵ����
//��20�еĸĶ�������ָ��Ƕ�׿���ʵ��pclassone->classone->lihua�����ϵĶ���pclassone���Զ�ָ��classone[0]��

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
