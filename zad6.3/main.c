#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int *tab;
    int x, y;
    int res;
    int k = 0;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    tab = malloc(sizeof(int)*n+1);
    for (int i = 0; i <= n; i++) tab[i] = 0;
    while(cnt < m)
    {
        scanf("%d %d", &x, &y);
        tab[x]++;
        tab[y]++;
        cnt++;
    }
    for (int i = 1; i <= n; i++)
    {
        k += tab[i]*(n-1-tab[i]);
    }
    res = (n*(n-1)*(n-2))/6-(k/2);
    printf("%d", res);
    free(tab);
}
