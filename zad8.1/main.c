#include <stdio.h>
#include <stdlib.h>

int get_lenght(long long int i)
{
    int len;
    len = 0;
    while (i != 0)
    {
        i /= 10;
        len += 1;
    }
    return len;
}

int main() {
    long long int S, x;
    scanf("%lld", &S);
    long long int len = get_lenght(S);

    x = 1;
    for (int i = 1; i < len; i++)
    {
        x *= 10;
        x += 1;
    }

    int *num = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        num[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        while (S >= x)
        {
            num[i] += 1;
            S -= x;
            if (num[i] > 9)
            {
                printf("-1");
                free(num);
                return 0;
            }
        }
        x /= 10;
    }
    if (num[len-1] > 9)
    {
        free(num);
        printf("%d", -1);
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d", num[i]);
    }

    free(num);
    return 1;
}