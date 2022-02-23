#include <stdio.h>
#include <math.h>
int main()
{
    int min;
    int max;
    scanf("%d %d", &min, &max);

    int tab[10];
    int num;
    int sum;
    int cnt = 0;
    if (min % 2 != 0) min++;
    for(num=min; num<=max; num+=2)
    {
        sum = 0;
        for(int i = 1; i <= sqrt(num); i++)
        {
            if(num % i == 0 && i != num)
            {
                sum = sum + i;
                if(i != 1) sum = sum + (num/i);
            }
        }
        if(sum == num && sum != 0)
        {
            tab[cnt] = num;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int q = 0; q < cnt; q++)
    {
        printf("%d ", tab[q]);
    }
    return 0;
}