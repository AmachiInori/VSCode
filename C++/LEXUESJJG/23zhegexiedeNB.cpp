/*
 * @Author: your name
 * @Date: 2020-04-07 17:57:54
 * @LastEditTime: 2020-04-20 01:59:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\C++\LEXUESJJG\23zhegexiedeNB.cpp
 */
#include <iostream>
#include <string>
#define techniJikyuu 100
using namespace std;

class employee
{
protected:
    string name;
    float gekkyuu;
public:
    employee(string str){name = str;}
    virtual ~employee(){};

    void print()
    {
        this -> calcuKyuu();        //这句我自己都觉得太强了！！
        cout << name << "本月工资" << gekkyuu << endl;
    }
    virtual void calcuKyuu() = 0;
};

class manager : virtual public employee
{
protected:
    int kyuuryouu;
public:
    manager(string name, int ryouu) : employee(name){kyuuryouu = ryouu;}
    virtual ~manager(){};

    void calcuKyuu()override{employee::gekkyuu = kyuuryouu;}
};

class technician : public employee
{
    int hours;
public:
    technician(string name, int h) : employee(name){hours = h;}
    ~technician(){}

    void calcuKyuu()override{employee::gekkyuu = hours * techniJikyuu;}
};

class sales : virtual public employee
{
protected:
    int uriiki;
public:
    sales(string name, int ur) : employee(name){uriiki = ur;}
    virtual ~sales(){}

    void calcuKyuu()override{employee::gekkyuu = 0.04 * (float)uriiki;}
};

class salesManager : public sales, public manager
{
public:
    salesManager(string name, int ryouu, int ur) : employee(name), sales(name, ur), manager(name, ryouu)
    {
        manager::kyuuryouu = ryouu;
        sales::uriiki = ur;
    }
    ~salesManager(){}

    void calcuKyuu()override{gekkyuu = kyuuryouu + uriiki * 0.005;}
};

int main()
{
    int h, a, b;
    cin >> h >> a >> b;
    manager man = manager("Tom", 8000);
    technician tec = technician("John", h);
    salesManager sm = salesManager("Antony", 5000, a);
    sales sa = sales("Jane", b);

    man.print();
    tec.print();
    sm.print();
    sa.print();

    system("pause");
    return 0;
}