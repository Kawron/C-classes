#include <stdio.h>
#include <stdlib.h>

int compare( const void*a, const void*b)
{
    return (*(int*)a - *(int*)b);
}

int check(int num, int* tab, int N, int K)
{
    int i = num + 1;
    // w prawo
    while ( i < N)
    {
        if (tab[i] <= tab[num] + K)
        {
            if (tab[i] != tab[num]) return 1;
            else
            {
                i++;
                continue;
            }
        }
        break;
    }

    i = num -1;
    // w lewo
    while ( i >= 0)
    {
        if (tab[i] >= tab[num] - K)
        {
            if (tab[i] != tab[num]) return 1;
            else
            {
                i--;
                continue;
            }
        }
        break;
    }
    return 0;
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    int tab[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&tab[i]);
    }
    qsort(tab, N, sizeof(int), compare);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (check(i, tab, N, K) == 1) cnt++;
    }
    printf("%d", cnt);
}
