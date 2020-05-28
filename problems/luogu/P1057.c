#include <stdio.h>
long memory[31][31];
int maxnumber = 0;
long DFS(int point, int times);
int distance(int point);
int pointcalcu(int point, int addNumber);
void Initialization();
int main()
{
    int times;
    scanf("%d%d", &maxnumber, &times);
    Initialization();
    printf("%ld", DFS(1, times));
    getchar();
    getchar();
    return 0;
}

void Initialization()
{
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            memory[i][j] = -1;
        }
    }
}
long DFS(int point, int times)
{
    if (memory[point][times] != -1)
    {
        return memory[point][times];
    }
    else
    {
        long result = 0;
        if (distance(point) == times)
        {
            result = 1;
        }
        else if (distance(point) < times)
        {
            result += DFS(pointcalcu(point, 1), times - 1) + DFS(pointcalcu(point, -1), times - 1);
        }
        else
        {
            result = 0;
        }
        memory[point][times] = result;
        return result;
    }
}

int distance(int point)
{
    if (point > (maxnumber + 1) / 2)
    {
        return maxnumber - point + 1;
    }
    else
    {
        return point - 1;
    }
}

int pointcalcu(int point, int addNumber)
{
    int temp = point + addNumber;
    if (temp > maxnumber)
    {
        return 1;
    }
    else if (temp < 1)
    {
        return maxnumber;
    }
    else
    {
        return temp;
    }
}
