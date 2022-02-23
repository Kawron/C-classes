#include <stdio.h>
#include <stdlib.h>
// genreujemy
// wpisujemy do tab gdy gotowe
// radix sort

int cnt = 1;
int flag = -1;

void genrate_aux(int n, int *num, int idx, int k)
{
    if (n == idx)
    {
        if (cnt == k)
        {
            // print result
            for (int i = 0; i < n; i++)
            {
                printf("%d", num[i]);
                flag = 1;
            }
        }
        cnt += 1;
        return;
    }
    if (num[idx-1] == 1)
    {
        num[idx] = 0;
        genrate_aux(n, num, idx+1, k);
    }
    if (num[idx-1] == 0)
    {
        num[idx] = 0;
        genrate_aux(n, num, idx+1, k);
        num[idx] = 1;
        genrate_aux(n, num, idx+1, k);
    }
}

void generate_main(int n, int k)
{
    int* num;
    num = malloc(n*sizeof(int));
    for (int i = 1; i < n; i++)
    {
        num[i] = -1;
    }

    // starts with '0'
    num[0] = 0;
    genrate_aux(n, num, 1, k);
    // starts with '1'
    num[0] = 1;
    genrate_aux(n, num, 1, k);

    free(num);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    generate_main(n, k);
    if (flag == -1) printf("%d", flag);
}