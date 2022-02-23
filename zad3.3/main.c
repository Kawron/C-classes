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

int check(int num)
{
    int sum = 0;
    while (1)
    {
        while (num != 0)
        {
            sum += (num % 10)*(num % 10);
            num = num / 10;
        }
        if (sum == 1) return 1;
        if (sum == 4) return 0;
        num = sum;
        sum = 0;

    }
}

int main()
{
    int L, U, K;
    scanf("%d %d %d", &L, &U, &K);
    while (L <= U)
    {
        if (is_prime(L) == 1 && check(L) == 1)
        {
            K -= 1;
            if (K == 0)
            {
                printf("%d", L);
                return 1;
            }
            L++;
        }
        L++;
    }
    printf("%d", -1);
    return 0;
}
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

int check(int num)
{
    int sum = 0;
    while (1)
    {
        while (num != 0)
        {
            sum += (num % 10)*(num % 10);
            num = num / 10;
        }
        if (sum == 1) return 1;
        if (sum == 4) return 0;
        num = sum;
        sum = 0;

    }
}

int main()
{
    int L, U, K;
    scanf("%d %d %d", &L, &U, &K);
    while (L <= U)
    {
        if (is_prime(L) == 1 && check(L) == 1)
        {
            K -= 1;
            if (K == 0)
            {
                printf("%d", L);
                return 1;
            }
            L++;
        }
        L++;
    }
    printf("%d", -1);
    return 0;
}
