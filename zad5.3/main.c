#include <stdio.h>
#include <stdlib.h>

void print_res(int *tab, int n)
{
    for (int i = 0; i < n*2; i += 2)
    {
        printf("%d %d \n", tab[i], tab[i+1]);
    }
}

//spr czy w zasiegu
int check(int **tab, int i, int j, int n, int r)
{
    if (i-r < 0) return 0;
    if (i + r >= n) return 0;
    if (j - r < 0) return 0;
    if (j + r >= n) return 0;
    return 1;
}

int sum(int **tab, int i, int j, int k, int r)
{
    int x;
    int y;
    int suma = 0;
    x = j - r;
    y = i - r;
    // gorna krawedz
    for (x; x < j + r; x++) suma += tab[y][x];
    // prawa krawędź
    for (y; y < i + r; y++) suma += tab[y][x];
    // dolna krawedz
    for (x; x > j-r; x--) suma += tab[y][x];
    // lewa krawedz
    for (y; y > i-r; y--) suma += tab[y][x];

    if (suma == k) return 1;
    return 0;
}

void traverse(int **tab, int n, int k)
{
    int *aux;
    aux = malloc((n*n) * sizeof(int));
    int r = 1;
    int cnt = 0;
    int idx = 0;
    while (r <= n/2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check(tab, i, j, n, r) == 1)
                {
                    if (sum(tab, i, j, k, r) == 1)
                    {
                        cnt ++;
                        aux[idx] = i;
                        aux[idx + 1] = j;
                        idx += 2;
                    }
                }
            }
        }
        r += 2;
    }
    printf("%d\n", cnt);
    print_res(aux, cnt);
    free(aux);
}

int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int **tab;
    tab = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        tab[i] = malloc(n * sizeof(*(tab[i])));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }
    traverse(tab, n, k);
    for (int i = 0; i < n; i++)
    {
        free(tab[i]);
    }
    free(tab);
}
