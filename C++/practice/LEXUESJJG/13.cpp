#include <iostream>
#include <string>
using namespace std;

int operator ==(string a, string b)
{
    if (a.length() != b.length())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if (a == b)
        cout << "str1=str2" << endl;
    else
        cout << "str1!=str2" << endl;
    
    system("pause");
    return 0;
}