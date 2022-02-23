#include <stdio.h>

int pow_two(int num)
{
    while (num % 2 == 0)
    {
        num = num / 2;
    }
    if (num > 1) return 0;
    else return 1;
}

int main()
{
    long s;
    long t;
    scanf("%ld %ld", &s, &t);
    long copy = t;
    if (t == 1)
    {
        if (s == 1) return 0;
        else
        {
            printf("/");
            return 0;
        }
    }

    int many_s = 0;
    int many_2 = 0;
    while (copy % s == 0)
    {
        many_s++;
        copy = copy / s;
    }
    while (copy % 2 == 0)
    {
        many_2++;
        copy = copy / 2;
    }
    char res[100];
    int index = 0;
    int x;
    int aux;

    if (many_s == 0 && s != 1)
    {
        res[index] = '/';
        res[index + 1] = '+';
        index += 2;
        many_s = many_2;
        s = 2;
        many_2 = 0;

    }
    if (copy > 1)
    {
        printf("NO\n");
        return 0;
    }
    if (many_s != 0 && many_s != 1 && pow_two(many_s) == 0)
    {
        if (s == 2)
        {
            while (pow_two(many_s) == 0)
            {
                many_s--;
                many_2++;
            }
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    while (many_s >= 2)
    {
        aux = many_2 / many_s;
        x = 0;
        while (x < aux)
        {
            res[index] = '+';
            index++;
            x++;
        }
        many_2 = many_2 - (many_s * aux);
        res[index] = '*';
        index ++;
        many_s /= 2;
    }
    while (many_2 > 0)
    {
        res[index] = '+';
        index++;
        many_2--;
    }
    for (int j=0; j < index; j++) printf("%c", res[j]);
    return 0;
}