#include <stdio.h>
#include <malloc.h>
#include <string.h>

int mod(int* num, int len)
{
    if (num[len-1] == 0) return 0;
    return 1;
}

int divide_dec(int* num, int size)
{
    int i = 0;
    int rest = 0;
    int tmp;
    while (i < size)
    {
        tmp = num[i];
        num[i] = (num[i]+rest) / 2;
        rest = (tmp % 2)*10;
        i++;
    }
    return rest/10;
}

void divide(int* num, int size)
{
    for (int i = size; i > 0; i--)
    {
        num[i] = num[i-1];
    }
}

void add(int* num, int x, int size)
{
    int rest = 1;
    int tmp;
    if (x == 1)
    {
        for (int j = size-1; j >= 0; j--)
        {
            tmp = num[j];
            num[j] = (num[j] + rest) % 2;
            rest = (tmp + rest) / 2;
        }
    }
}

void subtract(int* num, int x, int size)
{
    int rest = 1;
    int tmp;
    if (x == 1)
    {
        for (int j = size-1; j >= 0; j--)
        {
            tmp = num[j];
            num[j] = abs((num[j] - rest));
            rest = abs((tmp - rest));
            if (rest == 0) break;
        }
    }
}

int is_zero(int* num, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (num[i] != 0) flag = 1;
    }
    return flag;
}

int res(int* bin, int* ATM, int cnt)
{
    for (int i = 0; i < 100; i++)
    {
        ATM[i] = mod(bin, 200);
        if (cnt % 2 == 0)
        {
            subtract(bin, ATM[i], 200);
        }
        else
        {
            add(bin, ATM[i], 200);
        }
        divide(bin, 200);
        cnt ++;
    }
    if (is_zero(bin, 200) == 1)
    {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < 100; i++)
    {
        if (ATM[i] == 1) printf("%d ", i);
    }
    return 1;
}

int main()
{
    char* input;
    input = malloc(30*sizeof(char));
    scanf("%s", input);
    int len = strlen(input);
    int* num;
    num = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {
        num[i] = (int)input[i] - 48;
    }
    free(input);
    int* ATM;
    ATM = malloc(100*sizeof(int));
    for (int i = 0; i < 100; i++) ATM[i] = 0;

    // convert
    int* bin;
    bin = malloc(200*sizeof(int));
    for (int i = 0; i < 200; i++) bin[i] = 0;
    int k = 199;
    while (is_zero(num, len) == 1)
    {
        bin[k] = divide_dec(num, len);
        k--;
    }
    free(num);
    //copy
    int* copy_bin = malloc(200*sizeof(int));
    for (int i = 0; i < 200; i++) copy_bin[i] = bin[i];

    // main loop
    res(bin, ATM, 0);
    printf("\n");
    for (int i = 0; i < 100; i++) ATM[i] = 0;
    res(copy_bin, ATM, 1);
    free(copy_bin);
    free(bin);
    free(ATM);
}
