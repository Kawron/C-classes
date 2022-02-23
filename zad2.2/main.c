#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>

int main()
{
    int m;
    int b;
    scanf("%d%d", &m, &b);
    int flag = false;
    int num;
    int index;
    double sum;
    double k = m;
    double digit;
    char* tab = malloc(sizeof(char)*m);
    for (int i = pow(b, m-1); i < pow(b, m); i++)
    {
        num = i;
        index = m-1;
        sum = 0;
        while (num != 0)
        {
            digit = num % b;
            sum += pow(digit, k);
            if (digit >= 10)
            {
                digit -= 10;
                tab[index] = 'A' + digit;
            }
            else
            {
                tab[index] = '0' + digit;
            }
            num = num / b;
            index --;
        }
        if (sum == i)
        {
            printf("%s ", tab);
            flag = true;
        }
    }
    if (flag == false)
    {
        printf("NO");
    }
    free(tab);
    return 0;
}
