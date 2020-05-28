#include <iostream>

class NumberSet
{
    int *Set;
    int number;

public:
    NumberSet(int n, int * str)
    {
        number = n;
        Set = str;
    }

    friend NumberSet operator+(NumberSet a, NumberSet b)
    {
        int count = 0;
        int waruiLoca[b.number];
        for (int i = 0; i < b.number; i++)
        {
            waruiLoca[i] = 0;
        }
        
        for (int i = 0; i < b.number; i++)
        {
            for (int j = 0; j < a.number; j++)
            {
                if (b.Set[i] == a.Set[j]) 
                {
                    waruiLoca[count] = i;
                    count++;
                    break;
                }
            }
        }
        int *ResultStr = new int [a.number + b.number - count];
        
        int writePoi = 0;
        for (int i = 0; i < a.number; i++, writePoi++)
        {
            ResultStr[writePoi] = a.Set[i];
        }
        for (int i = 0; i < b.number; i++, writePoi++)
        {
            ResultStr[writePoi] = b.Set[i];
            for (int j = 0; j < count; j++)
            {
                if (i == waruiLoca[j])
                {
                    writePoi--;
                }
            }
        }
        
        NumberSet Res(a.number + b.number - count, ResultStr);
        return Res;
    }

    friend NumberSet operator-(NumberSet a, NumberSet b)
    {
        int count = 0;
        int waruiLoca[a.number];
        for (int i = 0; i < a.number; i++)
        {
            waruiLoca[i] = 0;
        }
        for (int i = 0; i < b.number; i++)
        {
            for (int j = 0; j < a.number; j++)
            {
                if (b.Set[i] == a.Set[j]) 
                {
                    waruiLoca[count] = j;
                    count++;
                    break;
                }
            }
        }
        int *ResultStr = new int [a.number - count];
        
        int writePoi = 0;

        for (int i = 0; i < a.number; i++, writePoi++)
        {
            ResultStr[writePoi] = a.Set[i];
            for (int j = 0; j < count; j++)
            {
                if (i == waruiLoca[j])
                {
                    writePoi--;
                }
            }
        }
        
        NumberSet Res(a.number - count, ResultStr);
        return Res;
    }

    friend std::ostream & operator<<(std::ostream & ost, const NumberSet & a) 
    {
        for (int i = 0; i < a.number; i++)
        {
            if (i != a.number - 1)
                ost << a.Set[i] << " ";
            else
                ost << a.Set[i];
        }
        ost << std::endl;
        return ost;
    }
};

int main()
{
    int numberF, numberS;
    int *SetF, *SetS;
    std::cin >> numberF;
    SetF = new int [numberF];
    for (int i = 0; i < numberF; i++)
    {
        std::cin >> SetF[i];
    }
    std::cin >> numberS;
    SetS = new int [numberS];
    for (int i = 0; i < numberS; i++)
    {
        std::cin >> SetS[i];
    }
    NumberSet a(numberF, SetF);
    NumberSet b(numberS, SetS);
    NumberSet resF = a + b;
    NumberSet resS = a - b;
    std::cout << "int1+int2=" << resF;
    std::cout << "int1-int2=" << resS;

    std::cin.get();
    std::cin.get();
    return 0;
}