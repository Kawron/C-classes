#include <stdio.h>
#include <stdlib.h>

int max(int x, int y, int z, int t, int s)
{
    if (x >= y && x >= z && x >= t && x >= s) return x;
    if (y >= x && y >= z && y >= t && y >= s) return y;
    if (z >= x && z >= y && z >= t && z >= s) return z;
    if (t >= x && t >= y && t >= z && t >= s) return t;
    if (s >= x && s >= y && s >= z && s >= t) return s;
    else return -1;
}

int right(int **tab, int k, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tab[x][y+i];
    }
    return sum;
}

int down(int **tab, int k, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tab[x+i][y];
    }
    return sum;
}

int right_down(int **tab, int k, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tab[x+i][y+i];
    }
    return sum;
}

int right_up(int **tab, int k, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tab[x-i][y+i];
    }
    return sum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int **input_tab;
    int **tab;
    // deklaracje
    input_tab = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        input_tab[i] = malloc(n*sizeof(int));
    }

    tab = malloc(3*n*sizeof(int*));
    for (int i = 0; i < 3*n; i++)
    {
        tab[i] = malloc(3*n*sizeof(int));
    }
    // wpisywanie wartosci
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &input_tab[i][j]);
        }
    }
    // skopiowanie wartosci do wiekszej tablicy
    for (int i = 0; i < 3*n; i++)
    {
        for (int j = 0; j < 3*n; j++)
        {
            tab[i][j] = input_tab[i%n][j%n];
        }
    }

    int maxi = -2147483648;
    for (int x = n; x < 2*n; x++)
    {
        for (int y = n; y < 2*n; y++)
        {
            maxi = max(right(tab, k, x, y), down(tab, k, x, y), right_down(tab, k, x, y), right_up(tab,k,x,y), maxi);
        }
    }
    printf("%d", maxi);
    // free
    for (int i = 0; i < 3*n; i++)
    {
        free(tab[i]);
    }
    free(tab);
    for (int i = 0; i < n; i++)
    {
        free(input_tab[i]);
    }
    free(input_tab);
}
