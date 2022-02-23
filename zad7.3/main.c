#include <stdio.h>
#include <stdlib.h>

int sum(int row, int col, int k, int l, int **T, int **P)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (P[i][j] == 1)
            {
                sum += T[row+i][col+j];
            }
        }
    }
    return sum;
}

int cover(int **T, int **P, int n, int k, int l)
{
    int maxi = -1;
    int suma;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row + k < n && col + l < n)
            {
                suma = sum(row, col, k, l, T, P);
                if (suma > maxi) maxi = suma;
            }
        }
    }
    return maxi;
}

int main()
{
    int n, k, l, res;
    scanf("%d %d %d", &n, &k, &l);
    int **T;
    int **P;

    T = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        T[i] = malloc(n*sizeof(int));
    }

    P = malloc(k*sizeof(int*));
    for (int i = 0; i < k; i++)
    {
        P[i] = malloc(l*sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &T[i][j]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            scanf("%d", &P[i][j]);
        }
    }

    res = cover(T, P, n, k, l);
    printf("%d", res);
    // free
    for (int i = 0; i < n; i++)
    {
        free(T[i]);
    }
    free(T);
    for (int i = 0; i < k; i++)
    {
        free(P[i]);
    }
    free(P);
}