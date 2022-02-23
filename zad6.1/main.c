#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int abs(int x)
{
    if (x < 0) x = x * (-1);
    return x;
}

void change(int **tab, int *points)
{
    int x1, y1, x2, y2;
    x1 = points[0];
    y1 = points[1];
    x2 = points[2];
    y2 = points[3];
    int i, width, height;
    int j = y1+1;
    while (j <= y2)
    {
        i = x1+1;
        while (i <= x2)
        {
            width = abs(-100-i)-1;
            height = abs(100-j);
            if (tab[height][width] == 1)
            {
                tab[height][width] = 0;
            }
            else
            {
                tab[height][width] = 1;
            }
            i++;
        }
        j++;
    }
}

int main()
{
    int **tab;
    tab = malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        tab[i] = malloc(sizeof(*(tab[i])) * SIZE);
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tab[i][j] = 1;
        }
    }
    int n;
    scanf("%d", &n);
    int **points;
    points = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        points[i] = malloc(sizeof(int) * 4);
        scanf("%d %d %d %d", &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
    }
    for (int i = 0; i < n; i++)
    {
        change(tab, points[i]);
    }
    int cnt = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (tab[i][j] == 0) cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 0; i < SIZE; i++) free(tab[i]);
    free(tab);
    for (int i = 0; i < n; i++) free(points[i]);
    free(points);
}
