#include <stdio.h>
#include <stdlib.h>
int compare( const void*a, const void*b)
{
    return (*(int*)b - *(int*)a);
}
int main()
{
    int N;
    int K;
    int sum = 0;
    scanf("%d%d", &N, &K);
    int tab[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &tab[i]);
    }
    qsort(tab, N, sizeof(int), compare);

    for(int i = 0; i < K; i++)
    {
        tab[i] = tab[i] / 2;
        sum = sum + tab[i];
    }

    for(int i = K; i < N; i++)
    {
        sum = sum + tab[i];
    }
    printf("%d", sum);
}
