#include <stdio.h>
#include <malloc.h>
#include <string.h>

int find_substring(char* tab, int size)
{
    int pointer = 0;
    int maxi, tmp;
    int* sub;
    int index = 0;

    sub = malloc(51*sizeof(int));
    for (int i = 0; i < 51; i++)
    {
        sub[i] = -1;
    }

    while (pointer < size)
    {
        maxi = -1;
        tmp = -1;
        for (int i = pointer; i < size; i++)
        {
            if ((int)tab[i] > maxi)
            {
                maxi = (int)tab[i];
                tmp = i;
            }
        }
        pointer = tmp + 1;
        sub[index] = tmp;
        index ++;
    }

    for (int i = 0; i < 51; i++)
    {
        if (sub[i] != -1)
        {
            printf("%c", tab[sub[i]]);
        }
        else return 1;
    }
    free(sub);
    return 1;
}

int main()
{
    char* tab;
    tab = malloc(51*sizeof(char));
    scanf("%s", tab);
    int size;
    size = strlen(tab);
    find_substring(tab, size);
    free(tab);
}
