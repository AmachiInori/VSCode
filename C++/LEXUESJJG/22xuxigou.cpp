#include <iostream>

class Felid
{
public:
    Felid(){std::cout << "Felid constructor" << std::endl;}
    virtual ~Felid(){std::cout << "Felid destructor" << std::endl;}
    
    virtual void sound() = 0;
};

class Cat : public Felid
{
public:
    Cat(){std::cout << "Cat constructor" << std::endl;}
    ~Cat(){std::cout << "Cat destructor" << std::endl;}

    void sound()override{std::cout << "Miaow !" << std::endl;}
};

class Leopard : public Felid
{
public:
    Leopard(){std::cout << "Leopard constructor" << std::endl;}
    ~Leopard(){std::cout << "Leopard destructor" << std::endl;}

    void sound()override{std::cout << "Howl !" << std::endl;}
};

int main()
{
    Felid *fstr;
    fstr = new Cat;
    fstr -> sound();
    delete fstr;
    fstr = new Leopard;
    fstr -> sound();
    delete fstr;

    system("pause");
    return 0;
}