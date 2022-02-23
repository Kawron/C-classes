#include <stdio.h>

int test(int num, int N, int M)
{
    if (num % M == 0) return 0;
    for (int i = 0; i < N; i++)
    {
        num = num ^ (1 << i);
        if (num != 0 && num % M == 0) return 1;
        num = num ^ (1 << i);
    }
    return 0;
}

int main()
{
    int n, m, cnt;
    scanf("%d %d", &n, &m);
    cnt = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        if (test(i,n,m) == 1) cnt++;
    }
    printf("%d", cnt);
}