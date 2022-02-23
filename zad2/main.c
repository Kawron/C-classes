#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
    int i = 5;

    if (num <= 1) return 0;

    if (num == 2 || num == 3) return 1;

    if (num % 2 == 0 || num % 3 ==0) return 0;

    while (i <= sqrt(num))
    {
    if (num % i == 0 || num % (i+2) == 0)
        {
            return 0;
        }
    i += 6;
    }
    return 1;
}

int series(int num)
{
    int prev = num % 10;
    num = num / 10;

    while (num != 0)
    {
        if (num % 10 > prev)
        {
            return 0;
        }
        prev = num % 10;
        num = num / 10;
    }
    return 1;
}

int main()
{
    int n;
    int i = 3;
    scanf("%d", &n);
    if (n > 2) printf("%d\n", 2);
    while (i < n)
    {
        if (series(i) == 1 && is_prime(i) == 1)
        {
            printf("%d\n", i);
        }
        i += 2;
    }
    return 0;
}
