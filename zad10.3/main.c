#include <stdio.h>
#include <malloc.h>

int XOR(int x, int y)
{
    if (x == 0 && y == 0) return 0;
    if (x == 1 && y ==1 ) return 0;
    else return 1;
}

int VAL(int idx, int **tab, int m, int ent)
{
    int tmp = 0;
    if (tab[idx-1][0] > 0 && tab[idx-1][1] > 0)
    {
        return XOR(VAL(tab[idx-1][0], tab, m, ent), VAL(tab[idx-1][1], tab, m, ent));
    }
    if (tab[idx-1][0] < 0 && tab[idx-1][1] < 0)
    {
        if (tab[idx-1][0]*(-1) == ent || tab[idx-1][1]*(-1) == ent) return 1;
        return 0;
    }
    if (tab[idx-1][0] > 0 && tab[idx-1][1] < 0)
    {
        if (tab[idx-1][1] * (-1) == ent) tmp = 1;
        return XOR(VAL(tab[idx-1][0], tab, m, ent), tmp);
    }
    if (tab[idx-1][0] < 0 && tab[idx-1][1] > 0)
    {
        if (tab[idx-1][0] * (-1) == ent) tmp = 1;
        return XOR(VAL(tab[idx-1][1], tab, m, ent), tmp);
    }
}

int find_a(int ent, int idx, int **tab, int m)
{
    int a;
    a = VAL(idx, tab, m, ent);
    return a;

}
int tab_to_dec(int *tab, int n)
{
    int res = 0;
    res += tab[n-1];
    int tmp = 1;
    int cnt = 1;
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j < cnt; j++)
        {
            tmp = tmp * tab[i] * 2;
        }
        res += tmp;
        cnt ++;
        tmp = 1;
    }
    return res;
}
int main()
{
    // input data
    int n, m, u;
    scanf("%d %d %d", &n, &m, &u);
    int **tab = malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++) tab[i] = malloc(2*sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &tab[i][0], &tab[i][1]);
    }

    char *low_c = malloc((n+1)*sizeof(char));
    char *up_c = malloc((n+1)*sizeof(char));
    for (int i = 0; i < n+1; i++) scanf("%c", &low_c[i]);
    for (int i = 0; i < n+1; i++) scanf("%c", &up_c[i]);

    int *low_t = malloc(n*sizeof(int));
    int *up_t = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        low_t[i] = (int)low_c[i+1] - 48;
        up_t[i] = (int)up_c[i+1] - 48;
    }
    int low = tab_to_dec(low_t, n);
    int up = tab_to_dec(up_t, n);
    printf("%d %d \n", low, up);
    // end input data

    int tmp = -1;
    int *factors_t = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        tmp = find_a(i+1, u, tab, m);
        factors_t[i] = tmp;
    }
    int factors = tab_to_dec(factors_t, n);
    printf("%d \n", factors);
    int x;
    int y;
    int cnt = 0;
    while (low <= up)
    {
        x = low;
        x = x & factors;
        y = x % 2;
        x = x / 2;
        while (x != 0)
        {
            y = XOR(x % 2, y);
            x = x / 2;
        }
        if (y == 1) cnt ++;
        low++;
    }
    printf("%d", cnt);
}
