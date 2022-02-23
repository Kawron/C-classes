#include <stdio.h>

int weight(int* tab, int idx, int w, int n)
{
    if (w < 0) return 0;
    if (w == 0) return 1;
    if (idx == n) return 0;
    if (weight(tab, idx+1, w-tab[idx], n) == 1) return 1;
    if (weight(tab, idx+1, w, n) == 1) return 1;
    if (weight(tab, idx+1, w+tab[idx], n) == 1) return 1;
    return 0;

}
int main()
{
    int n;
    int w;
    scanf("%d%d", &n, &w);
    int tab[n];
    int i;
    int sum = 0;
    for (i = 0; i<n; i++)
    {
        scanf("%d", &tab[i]);
        sum += tab[i];
    }
    if (sum < w)
    {
        printf("NO");
        return 0;
    }
    if (weight(tab, 0, w, n) == 1) printf("YES");
    else printf("NO");
    return 0;
}
