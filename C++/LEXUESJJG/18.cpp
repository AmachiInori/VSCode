#include <iostream>

class Animal
{
    int m_weight;
public:
    Animal(int m)
    {
        m_weight = m;
        return;
    }
    void getWeight()
    {
        std::cout << "My weight is " << m_weight << "kg." << std::endl;
    }
    ~Animal(){}
};

class Horse : virtual public Animal
{
public:
    Horse(int m) : Animal(m){}
    void print()
    {
        std::cout << "I can run." << std::endl;
    }
    ~Horse(){}
};

class Bird : virtual public Animal
{
public:
    Bird(int m) : Animal(m){}
    void print()
    {
        std::cout << "I can fly." << std::endl;
    }
    ~Bird(){}
};

class Pegasus : public Horse, public Bird
{
public:
    Pegasus(int m) : Animal(m), Bird(m), Horse(m){}
    void print()
    {
        std::cout << "I am a Pegasus." << std::endl;
        Animal::getWeight();
        Horse::print();
        Bird::print();
    }
    ~Pegasus(){}
};

int main()
{
    int m;
    std::cin >> m;
    Pegasus pea = Pegasus(m);
    pea.print();
    system("pause");
    return 0;
}