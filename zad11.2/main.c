#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int min(int x, int y)
{
    if (x > y) return y;
    if (x < y) return x;
    else return x;
}

int min_operations(int red[], int green[], int blue[], unsigned int n)
{
    int dp[200][8];
    unsigned int i;
    unsigned int j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= 7; j++) dp[i][j] = 1<<30;
    }

    dp[0][0] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
        {
            dp[i + 1][j | 1] = min(dp[i + 1][j | 1], dp[i][j] + green[i] + blue[i]);
            dp[i + 1][j | 2] = min(dp[i + 1][j | 2], dp[i][j] + red[i] + blue[i]);
            dp[i + 1][j | 4] = min(dp[i + 1][j | 4], dp[i][j] + red[i] + green[i]);
        }
    }
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (red[i]) j |= 1;
        if (green[i]) j |= 2;
        if (blue[i]) j |= 4;
    }
    if (dp[n][j] >= (1<<30)) dp[n][j] = -1;
    return dp[n][j];
}


int main()
{
    unsigned int n;
    scanf("%d",&n);
    int* red = malloc(sizeof(int)*n);
    int* green = malloc(sizeof(int)*n);
    int* blue = malloc(sizeof(int)*n);

    for (unsigned int i = 0; i < n;i++) scanf("%d",&red[i]);
    for (unsigned int i = 0; i < n;i++) scanf("%d",&green[i]);
    for (unsigned int i = 0; i < n; i++) scanf("%d",&blue[i]);

    printf("%d", min_operations(red, green, blue, n));
    free(red);
    free(blue);
    free(green);
}