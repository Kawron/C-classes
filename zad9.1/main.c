#include <stdio.h>
#include <string.h>
#include <malloc.h>

int is_prime(int x)
{
    if (x % 2 == 0) return 0;
    for (int i = 3; i*i <= x; i += 2)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

int compare(char* x, char* y, int len)
{
    // sprawdza czy y jest mniejsze od x
    for (int i = 0; i < len; i++)
    {
        if (x[i] < y[i]) return 0;
        else if (x[i] > y[i]) return 1;
    }
    return 0;
}

int main()
{
    //entering data
    char* S;
    S = malloc(51*sizeof(char));
    scanf("%s", S);
    int len = strlen(S);
    char* res;
    res = malloc(len*sizeof(char));
    for (int i = 0; i < len; i++)
    {
        res[i] = 'z';
    }

    //tablica liczb pierwszych
    int cnt = 1;
    int idx = 1;
    for (int i = 3; i < len; i++)
    {
        if (is_prime(i) == 1) cnt++;
    }
    int* primes = malloc(cnt*sizeof(int));
    primes[0] = 2;
    for (int i = 3; i < len; i++)
    {
        if (is_prime(i) == 1)
        {
            primes[idx] = i;
            idx ++;
        }
    }
    int num_primes = cnt; // ile mamy pierwszych do dyspozycji

    // ile mamy najlepszych o
    char mini = 'z';
    cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (S[i] < mini) mini = S[i];
    }
    for (int i = 0; i < len; i++)
    {
        if (S[i] == mini) cnt++;
    }
    int* index;
    index = malloc(cnt*sizeof(int));
    char* best_str;
    best_str = malloc(len*sizeof(char));
    idx = 0;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == mini) index[idx] = i, idx++;
    }
    idx = 0;

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < num_primes; j++)
        {
            for (int k = 0; k < len; k++)
            {
                best_str[idx] = S[(index[i]+k*primes[j])%len];
                idx ++;
            }
            if (compare(res, best_str, len) == 1)
            {
                for (int l = 0; l < len; l++)
                {
                    res[l] = best_str[l];
                }
            }
            idx = 0;
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c", res[i]);
    }
    free(index), free(res), free(S), free(primes), free(best_str);
}
