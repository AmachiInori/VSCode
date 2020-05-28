#include <stdio.h>
#include <math.h>

void Binary(int number);

int main()
{
    int originNumber;
    scanf("%d", &originNumber);
    Binary(originNumber);

    getchar();
    getchar();
    return 0;
}

void Binary(int number)
{
    if (number <= 0) return;
    int tempResult = 0;
    for (int i = 0; (int)pow(2,i) < number; i++) tempResult = i;
    if (tempResult > 3)
    {
        printf("2(");
        Binary(tempResult);
        Binary(number - (int)pow(2,tempResult));
        printf(")");
    }
    else if (tempResult == 3)
    {
        printf("2+2(0)");
        return;
    }
    else if (tempResult == 2)
    {
        printf("2");
        return;
    }
    else if (tempResult == 1)
    {
        printf("2(0)");
        return;
    }
}