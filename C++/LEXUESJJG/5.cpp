#include <iostream>
using namespace std;

class DATE
{
    int m_year;
    int m_month;
    int m_day;
public:
    DATE(int y, int m, int d);
    void showDate();
    int getDay();
    int getMonth();
    int getYear();
    ~DATE();
};

DATE::DATE(int y, int m, int d)
{
    m_year = y;
    m_month = m;
    m_day = d;
}

void DATE::showDate()
{
    cout << m_year << "/" << m_month << "/" << m_day << endl;
}

int DATE::getDay()
{
    return  m_day;
}

int DATE::getYear()
{
    return m_year;
}

int DATE::getMonth()
{
    return m_month;
}

DATE::~DATE()
{
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    DATE theDate(y, m, d);
    theDate.showDate();
    cout << "year " << theDate.getYear() << endl;
    cout << "month " << theDate.getMonth() << endl;
    cout << "day " << theDate.getDay() << endl;
    getchar();
    getchar();
    theDate.~DATE();
    return 0;
}