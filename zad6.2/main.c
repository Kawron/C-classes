#include <stdio.h>
#include <string.h>

char *tab1[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int val1[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

int roman_to_num(char *num)
{
    int len = strlen(num);
    int cnt;
    int value = 0;
    int i = 0;
    int j;
    while (i < len)
    {
        cnt = 0;
        j = 0;
        while (j < 13)
        {
            if (cnt % 2 == 0)
            {
                if (num[i] == tab1[j][0])
                {
                    value += val1[j];
                    i++;
                    break;
                }
            }
            else
            {
                if (num[i] == tab1[j][0] && num[i+1] == tab1[j][1])
                {
                    value += val1[j];
                    i += 2;
                    break;
                }
            }
            j++;
            cnt ++;
        }
    }
    return value;
}

void num_to_roman(int x)
{
    char res[20];
    res[0] = 0;
    int j;
    while (x > 0)
    {
        j = 0;
        while (j < 13)
        {
            if (val1[j] <= x)
            {
                strcat(res, tab1[j]);
                x -= val1[j];
                break;
            }
            j++;
        }
    }
    printf("%s", res);
}

int main()
{
    char num1[20];
    char num2[20];
    scanf("%s %s", num1, num2);
    int res1 = roman_to_num(num1);
    int res2 = roman_to_num(num2);
    int res = res1 + res2;
    num_to_roman(res);
}
