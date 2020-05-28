#include <iostream>

class BaseString
{
    char *chstr;
    int length;
public:
    BaseString(char *s)
    {
        chstr = s;
        int i = 0;
        for (i = 0; s[i] != 0; i++);
        length = i;
    }
    int getLength()
    {
        return length;
    }
    char getWord(int loca)
    {
        if(loca < 0 || loca >= length) return 0;
        else return chstr[loca];
    }
    ~BaseString()
    {}
};

class reString : public BaseString
{
public:
    reString(char *s) : BaseString(s){}
    void print()
    {
        std::cout << "倒序输出：";
        for (int i = BaseString::getLength() - 1; i >= 0; i--)
        {
            std::cout << BaseString::getWord(i);
        }
        std::cout << std::endl;
    }
    ~reString(){}
};

class CopyString : public BaseString
{
public:
    CopyString(char *s) : BaseString(s){}
    void print()
    {
        std::cout << "复制输出：";
        for (int i = 0; i < BaseString::getLength(); i++)
        {
            std::cout << BaseString::getWord(i);
        }
        std::cout << std::endl;
    }
};

class CmpString : private BaseString
{
public:
    CmpString(char *s) : BaseString(s){};
    friend int cmp(CmpString a, CmpString b)
    {// eq 1, bueq 0
        if(a.getLength() != b.getLength()) return 0;
        for (int i = 0; i < a.getLength(); i++)
            if (a.getWord(i) != b.getWord(i)) return 0;
        return 1;
    }
    ~CmpString(){}
};

int main()
{
    char *s, *s2;
    s = new char[1024];
    std::cin.getline(s, 1024);
    reString r= reString(s);
    r.print();
    s = new char[1024];
    std::cin.getline(s, 1024);
    CopyString c = CopyString(s);
    c.print();
    s = new char[1024];
    s2 = new char[1024];
    std::cin.getline(s, 1024);
    std::cin.getline(s2, 1024);
    CmpString cm1 = CmpString(s);
    CmpString cm2 = CmpString(s2);
    if (cmp(cm1, cm2) == 1)
        std::cout << "判断结果：两字符串相等。" << std::endl;
    else
        std::cout << "判断结果：两字符串不相等。" << std::endl;
    system("pause");
    return 0;
}