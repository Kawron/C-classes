#include <stdio.h>
#include <stdlib.h>

int sum(int **tab, int i, int j, int r, int n)
{
    // obszar w ktorym bedziemy dodawac
    int starting_x = j - r;
    if(starting_x < 0) starting_x = 0;

    int starting_y = i - r;
    if(starting_y < 0) starting_y = 0;

    int ending_x = j + r;
    if(ending_x >= n) ending_x = n-1;

    int ending_y = i + r;
    if(ending_y >= n) ending_y = n-1;

    int suma = 0;
    for(int i = starting_y; i <= ending_y; i++)
    {
        for(int j = starting_x; j <= ending_x; j++)
        {
            suma += tab[i][j];
        }
    }
    return suma;
}

int main()
{
    int n;
    int r;
    scanf("%d %d", &n, &r);

    int **tab;
    tab = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        tab[i] = malloc(n * sizeof(int));
    }
    // enter data
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }
    // macierz wynikowa
    int **res;
    res = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        res[i] = malloc(n * sizeof(int));
    }
    // sumowanie
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res[i][j] = sum(tab, i, j, r, n);
        }
    }
    // wypisywanie
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
