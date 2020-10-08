#include <iostream>
#include <string>
using namespace std;

class person
{
    string name;
    string number;
public:
    person()
    {
        getline(cin, name);
        getline(cin, number);
    }
    void print()
    {
        cout << "Name:" << name << endl << "Number:" << number << endl;
    }
    ~person(){}
};

class student : public person
{
    string course;
    float grade;
public:
    student()
    {
        getline(cin, course);
        cin >> grade; 
    }
    void print()
    {
        cout << "Studentinformation:" << endl;
        person::print();
        cout << "Course:" << course << endl << "Grade:" << grade << endl << endl;
//        printf("%.1f\n\n", grade);
    }
    ~student(){}
};

class teacher : public person
{
    string pro;
    int paper;
public:
    teacher()
    {
        getline(cin, pro);
        cin >> paper; 
    }
    void print()
    {
        cout << "Teacherinformation:" << endl;
        person::print();
        cout << "pro:" << pro << endl << "paper:" << paper << endl;
    }
    ~teacher(){}
};

int main()
{
    student a;
    cin.get();
    teacher b;
    a.print();
    b.print();
    system("pause");
    return 0;}