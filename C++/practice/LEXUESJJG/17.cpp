#include <iostream>
#include <string>
using namespace std;

/*
SysName:BitLibrary
Num:1001
BookName:C++Language
BookConcern:Bitcon
Price:24.8
AuthorName:Lichunbao
AuthorAge:40
PrintTime:2001-10-10
*/

class book
{
    int bookNumber;
    string bookName;
    string press;
    float price;
public:
    book();
    void input();
    void print();
    ~book();
};

class author
{
    string name;
    int age;
    int printTimeA, printTimeB, printTimeC;
public:
    author();
    void input();
    void print();
    ~author();
};

class card : public book, public author
{
    string sysname;
public:
    card();
    void input();
    void print();
    ~card();
};

book::book()
{}

void book::input()
{
    cin >> bookNumber;
    cin.get();
    getline(cin, bookName);
    getline(cin, press);
    cin >> price;
}

void book::print()
{
    cout << "Num:" << bookNumber << endl << "BookName:" << bookName << endl;
    cout << "BookConcern:" << press << endl << "Price:" << price << endl;
    return;
}
book::~book()
{}

author::author()
{}

void author::input()
{
    cin.get();
    getline(cin, name);
    cin >> age;
    cin >> printTimeA >> printTimeB >> printTimeC;
}

void author::print()
{
    cout << "AuthorName:" << name << endl << "AuthorAge:" << age << endl;
    cout << "PrintTime:" << printTimeA << "-" << printTimeB << "-" << printTimeC << endl;
}

author::~author(){}

card::card(){}

void card::input()
{
    getline(cin, sysname);
    book::input();
    author::input();
}

void card::print()
{
    cout << "SysName:" << sysname << endl;
    book::print();
    author::print();
}

card::~card(){}

int main()
{
    card c;
    c.input();
    c.print();
    system("pause");
    return 0;
}