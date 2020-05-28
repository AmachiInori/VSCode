#include <iostream>
#define pi 3.14

class Acc_shape
{
public:
    float x;
    float y;
    Acc_shape(float a, float b)
    {
        x = a;
        y = b;
    }
    virtual float area() = 0;
    virtual void print() = 0;
    ~Acc_shape(){}
};

class triangle : public Acc_shape
{
public:
    triangle(float a, float b) : Acc_shape(a, b){};
    float area()override
    {
        return x * y * 0.5;
    }
    void print()override
    {
        std::cout << "triangleArea=" << area() << std::endl;
    }
    ~triangle(){};
};

class rectangle : public Acc_shape
{
public:
    rectangle(float a, float b) : Acc_shape(a, b){};
    float area()override
    {
        return x * y;
    }
    void print()override
    {
        std::cout << "rectangleArea=" << area() << std::endl;
    }
    ~rectangle(){};
};

class circle : public Acc_shape
{
public:
    circle(float a) : Acc_shape(a, 0){};
    float area()override
    {
        return x * x * pi;
    }
    void print()override
    {
        std::cout << "circleArea=" << area() << std::endl;
    }
    ~circle(){};
};

int main()
{
    float x, y;
    std::cin >> x >> y;
    triangle tr = triangle(x, y);
    rectangle re = rectangle(x, y);
    circle ci = circle(x);
    tr.print();
    re.print();
    ci.print();
    system("pause");
    return 0;
}