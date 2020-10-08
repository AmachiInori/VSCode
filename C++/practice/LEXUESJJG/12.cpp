#include <iostream>

class Student
{
    int number;
    int point;

public:
    Student()
    {
        std::cin >> number >> point;
    }

    friend int operator>(Student const a, Student const b)
    {
        if (a.point > b.point)
            return 1;
        else
            return 0;
    }

    friend std::ostream & operator<<(std::ostream & ost, Student const a)
    {
        return ost << "学号:" << a.number << "  成绩:" << a.point << std::endl;
    }

    ~Student(){}
};

int main()
{
    int tot;
    Student * StuStr;
    std::cin >> tot;
    StuStr = new Student [tot];
    /*
    for (int i = 0; i < tot; i++)
    {
        StuStr[i] = Student();
    }
    new会自动调用构造函数！！
    */

    for (int i = 0; i < tot; i++)
    {
        for (int j = 0; j < tot - 1; j++)
        {
            if (StuStr[j + 1] > StuStr[j])
            {
                Student temp = StuStr[j];
                StuStr[j] = StuStr[j + 1];
                StuStr[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < tot; i++)
    {
        std::cout << StuStr[i];
    }
    
    std::cin.get();
    std::cin.get();
    return 0;
}