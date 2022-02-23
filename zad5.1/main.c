#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    if (x < y) return x;
    else return y;
}

int max(int x, int y)
{
    if (x > y) return x;
    else return y;
}

int histogram(int *row, int n)
{
    int max_area = 0;
    int min_height = 0;
    int width = 0;
    for (int i = 0; i < n; i++)
    {
        min_height = row[i];
        max_area = max(max_area, row[i]);
        for (int j = i-1; j >= 0; j--)
        {
            min_height = min(min_height, row[j]);
            width = i - j + 1;
            max_area = max(max_area, width * min_height);
        }
    }
    return max_area;
}

void translate(int **tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] == 0) tab[i][j] = 1;
            else tab[i][j] = 0;
        }
    }
}

// korzystamy z algorytmu który traktuje każdy wiersz tablicy
// jak histogram i znajduje pole największego prostokąta pod nim
int main()
{
    int n;
    scanf("%d", &n);
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

    int max_area = 0;
    translate(tab, n);
    max_area = histogram(tab[0], n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] != 0)
            {
                tab[i][j] += tab[i-1][j];
            }
        }
        max_area = max(histogram(tab[i], n), max_area);
    }
    printf("%d", max_area);
    translate(tab, n);
    for (int i = 0; i < n; i++)
    {
        free(tab[i]);
    }
    free(tab);
}