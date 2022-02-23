#include <stdio.h>
#include <stdlib.h>

void print(int **tab, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void spiral(int **tab, int N)
{
    int i = 0;
    int j = 0;
    int cnt = 1;
    int border = 1;
    while (1)
    {
        // idziemy w prawo
        while (j < N-border)
        {
            tab[i][j] = cnt;
            j++;
            cnt++;
        }
        // idziemy w dol
        while (i < N-border)
        {
            tab[i][j] = cnt;
            i++;
            cnt++;
        }
        // idziemy w lewo
        while (j >= 0+border)
        {
            tab[i][j] = cnt;
            j--;
            cnt++;
        }
        // idziemy gore
        while (i >= 1+border)
        {
            tab[i][j] = cnt;
            i--;
            cnt++;
        }
        if (cnt == N*N)
        {
            tab[i][j] = cnt;
            break;
        }
        border ++;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int **tab;
    tab = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        tab[i] = malloc(N * sizeof(*(tab[i])));
    }
    spiral(tab, N);
    print(tab, N);
    for (int i = 0; i < N; i++)
    {
        free(tab[i]);
    }
    free(tab);
}