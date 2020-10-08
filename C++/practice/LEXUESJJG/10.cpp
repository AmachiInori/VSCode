#include <iostream>

class TIME
{
    int day;
    int month;
    int year;

public:
    TIME()
    {
        std::cin >> year >> month >> day;
    }

    friend std::ostream & operator<<(std::ostream & ost, const TIME & t) 
    {
//        ost <<  TIME.year << "-" << TIME.month << "-" << TIME.day << std::endl;
//        上述语句错误：由于参数被引用且是友元函数。
        ost <<  t.year << "-" << t.month << "-" << t.day << std::endl;
        return ost;
    }

    ~TIME(){};
};

int main()
{
    TIME t;
    std::cout << t;
    
    std::cin.get();
    std::cin.get();
    return 0;
}