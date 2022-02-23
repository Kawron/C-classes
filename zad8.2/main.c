#include <stdio.h>

unsigned long long int calc(int n)
{
    unsigned long long int k;
    if (n == 0) return 0;
    k = (n+1)/2;
    return k*k + calc(n/2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%llu", calc(n));
}