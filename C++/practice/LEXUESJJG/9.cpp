#include <iostream>
#include <math.h>
using namespace std;

class Cpoint
{
    float m_x;
    float m_y;

public:

    Cpoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    };

    ~Cpoint()
    {
    };

    friend float Distance(Cpoint a, Cpoint b)
    {
        return sqrt(pow(a.m_x - b.m_x, 2) + pow(a.m_y - b.m_y, 2)); 
    };
};

int main()
{
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    Cpoint A(ax, ay);
    Cpoint B(bx, by);
    cout << "Distance=" << Distance(A, B) << endl;
    
    cin.get();
    cin.get();
    return 0;
}