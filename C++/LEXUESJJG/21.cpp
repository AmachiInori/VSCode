#include <iostream>

class wripen
{
public:
    wripen(){};
    virtual void writing() = 0;
    ~wripen(){};
};

class pencil : public wripen
{
public:
    pencil(){};
    void writing()override
    {
        std::cout << "I'm a pencil." << std::endl;
    }
    ~pencil(){};
};

class pen : public wripen
{
public:
    pen(){};
    void writing()override
    {
        std::cout << "I'm a pen." << std::endl;
    }
    ~pen(){};
};

int main(int argc, char const *argv[])
{
    pencil c;
    pen p;
    wripen* wp;
    char ch = getchar();
    if (ch == 'c')
    {
        wp = &c;
    }
    else if(ch == 'p')
    {
        wp = &p;
    }
    wp -> writing();

    int a = system("pause");
    return 0;
}