#include <iostream>

class martrix
{
    int high, length;
    int ** str;
public:
    martrix(int h, int l, int** str);
    friend martrix operator+(martrix const a, martrix const b);
    friend martrix operator-(martrix const a, martrix const b);
    friend martrix operator*(martrix const a, martrix const b);
    friend std::ostream & operator<<(std::ostream & ost, martrix & a);
    int& operator()(int h, int l);
    ~martrix();
};

martrix::martrix(int h, int l, int** str_)
{
    high = h;
    length = l;
    
    str = str_;
}

martrix operator+(martrix a, martrix b) 
{//此处注意 若括号重载为int&引用，则不能用const，因为const与引用矛盾
    int** strRes = new int* [a.high];
    for (int i = 0; i < a.high; i++)
    {
        strRes[i] = new int [a.length];
        for (int j = 0; j < a.length; j++)
            strRes[i][j] = a(i, j) + b(i, j);
    }
    martrix res = martrix(a.high, a.length, strRes);
    return res;
}

martrix operator-(martrix a, martrix b) 
{
    int** strRes = new int* [a.high];
    for (int i = 0; i < a.high; i++)
    {
        strRes[i] = new int [a.length];
        for (int j = 0; j < a.length; j++)
            strRes[i][j] = a(i, j) - b(i, j);
        
    }
    martrix res = martrix(a.high, a.length, strRes);
    return res;
}

martrix operator*(martrix a, martrix b) 
{
    int** strRes = new int* [a.high];
    for (int i = 0; i < a.high; i++)
    {
        strRes[i] = new int [a.length];
        for (int j = 0; j < a.length; j++)
            strRes[i][j] = a(i, j) * b(i, j);
        
    }
    martrix res = martrix(a.high, a.length, strRes);
    return res;
}

std::ostream & operator<<(std::ostream & ost, martrix & a)
{
    for (int i = 0; i < a.high; i++)
    {
        for (int j = 0; j < a.length; j++)
            ost << a(i, j) << " ";
        ost << std::endl;
    }
    return ost;
}

int& martrix::operator()(int h, int l)
{
    return str[h][l];
}

martrix::~martrix()
{
    //delete str;  这句话太要命了 必须注释掉，否则在第一步加法完成之后矩阵就没了
}

int main()
{
    int **str1, **str2;
    int l, h;
    std::cin >> h >> l;

    str1 = new int* [h];
    for (int i = 0; i < h; i++)
    {
        str1[i] = new int [l];
        for (int j = 0; j < l; j++)
            std::cin >> str1[i][j];
    }
    
    str2 = new int* [h];
    for (int i = 0; i < h; i++)
    {
        str2[i] = new int [l];
        for (int j = 0; j < l; j++)
            std::cin >> str2[i][j];
    }

    martrix a(h, l, str1), b(h, l, str2);
    
    martrix c = a + b;
    std::cout << "c=a+b" << std::endl;
    std::cout << c;
    c = a - b;
    std::cout << "c=a-b" << std::endl;
    std::cout << c;
    c = a * b;
    std::cout << "c=a*b" << std::endl;
    std::cout << c;

    system("pause");
    return 0;
}