#include <stdio.h>

int calcuResult(int preN, int n, int k);
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d", calcuResult(1, n ,k));
    getchar();
    getchar();
    return 0;
}

int calcuResult(int preN, int n, int k)
{
    int result = 0;
    if (k > 1)
    {
        for (int i = preN; i <= n / k; i++)
        {
            result += calcuResult(i, n - i, k - 1);
        }
    }
    else if (k == 1)
    {
            result = 1;
    }
    return result;
}

/*
题目描述
将整数nn分成kk份，且每份不能为空，任意两个方案不相同(不考虑顺序)。

例如：n=7n=7，k=3k=3，下面三种分法被认为是相同的。

1,1,51,1,5;
1,5,11,5,1;
5,1,15,1,1.

问有多少种不同的分法。

输入格式
n,kn,k (6<n \le 2006<n≤200，2 \le k \le 62≤k≤6)

输出格式
11个整数，即不同的分法。
*/

//算法 DFS