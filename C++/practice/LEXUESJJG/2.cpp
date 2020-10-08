#include <iostream>
using namespace std;

class TIME
{
    int hour;
    int minu;
    int seco;
public:
    void in(int INhour, int INminu, int INseco);
    void out();
};

void TIME::in(int INhour, int INminu, int INseco)
{
    TIME::hour = INhour;
    TIME::minu = INminu;
    TIME::seco = INseco;
    return;
}

void TIME::out()
{
    cout << TIME::hour << ":" << TIME::minu << ":" << TIME:: seco << endl;
    return;
}

int main()
{
    TIME Temp;
    int hour, minu, seco;
    cin >> hour >> minu >> seco;
    Temp.in(hour, minu, seco);
    Temp.out();
    getchar();
    getchar();
    return 0;
}