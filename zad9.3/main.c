#include <stdio.h>
#include <malloc.h>

int one_or_zero(int x, int pos)
{
    int cnt = 1;
    if (x == 0) return 0;
    while (cnt != pos)
    {
        x /= 2;
        cnt ++;
    }
    return x % 2;
}

int compare(int x, int y, int pos)
{
    int div_x, div_y, cnt, res;
    res = 0;
    cnt = 1;
    while (x > 0 || y > 0)
    {
        div_x = x % 2;
        div_y = y % 2;
        if (cnt != pos)
        {
            if (div_x == 0 && div_y == 1)
            {
                res = 0;
                return res;
            }
        }
        else
        {
            if (div_x == 1 && div_y == 1) res = 1;
            else if (div_x == 1 && div_y == 0) res = 0;
            else if (div_x == 0 && div_y == 1) res = 0;
            else return 1;
        }
        x /= 2;
        y /= 2;
        cnt ++;
    }
    return res;
}

int get_len(int x)
{
    int cnt = 0;
    if (x == 0) return 1;
    while (x > 0)
    {
        x /= 2;
        cnt ++;
    }
    return cnt;
}

int main()
{
    int N, G;
    scanf("%d %d", &N, &G);
    int* tab = malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tab[i]);
    }
    int len = get_len(G);
    int mini = N+1;
    int cnt, res;
    while (len > 0)
    {
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            cnt += compare(G, tab[i], len);
        }
        if (cnt == 0)
        {
            printf("0");
            free(tab);
            return 0;
        }
        else if (cnt < mini) mini = cnt;
        len--;
    }
    free(tab);
    if (mini == N+1) printf("0");
    else printf("%d", mini);
}