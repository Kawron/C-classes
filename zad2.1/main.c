#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int tab[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
        sum += tab[i];
    }
    int half = 0;
    for (int j = 0; j < n; j++)
    {
        if ( tab[j] + half == sum - half)
        {
            printf("%d", j);
            return 1;
        }
        half += tab[j];
    }
    return 0;
}
