#include <stdio.h>

void main()
{
    int n;
    scanf("%d", &n);
    int x = 0;
    int y = 1;
    int tmp;
    while (x*y < n)
    {
        tmp = x+y;
        x = y;
        y = tmp;
    }
    if (x*y == n)
    {
        printf("YES");
    }
    else printf("NO");
}
