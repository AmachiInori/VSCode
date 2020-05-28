#include <iostream>
#define pi 3.14

class point
{
    int x;
    int y;
public:
    point()
    {
        std::cin >> x >> y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    ~point(){}
};

class Circle
{
    int r;
public:
    point p;
    Circle(int r_)
    {
        std::cin >> r;
    }
    int getR()
    {
        return r;
    }
    float Area()
    {
        return (float)r * r * pi;
    }
    ~Circle(){}
};

int main()
{
    int r;
    Circle theC(r);
    std::cout << "圆心位于(" << theC.p.getX() << "," << theC.p.getY() << ")半径为" 
    << theC.getR() << "的圆形面积是";
    printf("%.2f\n", theC.Area());
    system("pause");
    return 0; 
}