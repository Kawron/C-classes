#include <stdio.h>
#include <malloc.h>

int merge(int *tab, int i, int j, int N)
{
    // spr czy wyszlismy poza zakres
    if (j == N*N) return 0;

    int size = j+N;
    int start = i;
    // end to element za koncem tego co laczymy
    int end = j + N;
    int mid = j;
    int idx = 0;
    int *aux = (int*)malloc(sizeof(int)*(size));
    while(i != mid || j < end)
    {
        if(tab[i] < tab[j] && i < mid)
        {
            aux[idx] = tab[i];
            tab[i] = -1;
            i ++;
        }
        else if(tab[i] >= tab[j] && j < end)
        {
            aux[idx] = tab[j];
            tab[j] = -1;
            j ++;
        }
        // wyszlismy i lub j
        else if(j < end)
        {
            aux[idx] = tab[j];
            tab[j] = -1;
            j ++;
        }
        else if(i < mid)
        {
            aux[idx] = tab[i];
            tab[i] = -1;
            i ++;
        }
        idx ++;
    }

    // wpisujemy do tab
    idx = 0;
    while(idx < size)
    {
        tab[start] = aux[idx];
        idx ++;
        start ++;
    }
    free(aux);
    return 1;
}

void enter(int*tab, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &tab[(i*N)+j]);
        }
    }
}

void print(int *tab, int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%d ", tab[i]);
    }
}

void get_res(int *tab, int N) {
    int cnt = 0;
    int prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (tab[i] != prev) {
            prev = tab[i];
            cnt++;
        }
    }
    int *res = (int *) malloc(sizeof(int) * (cnt));

    prev = -1;
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        if (tab[i] != prev)
        {
            prev = tab[i];
            res[idx] = tab[i];
            idx ++;
        }
    }
    print(res, cnt);
    free(res);
}


int main()
{
    int N;
    scanf("%d", &N);

    int *tab = (int*)malloc(sizeof(int)*N*N);
    enter(tab, N);

    int i = 0;
    int j = N;
    while (1)
    {
        if(merge(tab,i ,j, N) == 0) break;
        else j += N;
    }

    get_res(tab, N*N);
    free(tab);
}
