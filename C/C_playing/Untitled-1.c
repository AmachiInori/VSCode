#include <stdio.h>
#include <math.h>
#define Number 0.524

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            float result = (float) j / (float) i;
            if ((int)floor(Number * 1000 + 0.5) % 2 == 0)
            {
                if (result >= Number - 0.0005 && result <= Number + 0.0004) //四舍六入五成双
                {
                    printf("%d, %d, %f\n", i, j, result);
                }
            }
            else
            {
                if (result >= Number - 0.0004 && result <= Number + 0.0005) 
                {
                    printf("%d, %d, %f\n", i, j, result);
                }
            }
        }
    }
    printf("End");
    getchar();
}