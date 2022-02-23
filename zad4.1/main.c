#include <stdio.h>
#define size 160

int main()
{
    int num;
    scanf("%d", &num);
    int tab[size];
    for (int i = 1; i < size; i++)
    {
        tab[i] = 0;
    }
    tab[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        int rest = 0;
        for (int j = 0; j < size; j++)
        {
            int num = rest + (tab[j]) * i;
            tab[j] = (num % 10);
            rest = num / 10;
        }
    }
    int i = size - 1;
    while (tab[i] == 0) i--;
    while (i >= 0)
    {
        printf("%d", tab[i]);
        i --;
    }
}
