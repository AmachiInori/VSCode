#include <iostream>
#define NUMBERS 3
#define LOW -32767
using namespace std;

int main()
{
    int maxi = LOW;
    for (int i = 0; i < NUMBERS; i++)
    {
        int temp;
        cin >> temp;
        if (temp >= maxi) maxi = temp;
    }
    cout << "Maximum:" << maxi << endl;
    getchar();
    getchar();
    return 0;
}