#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

int mid(double x1, double y1, double x2, double y2, int idx, double *A, double *B)
{
    A[idx] = (x1 + x2) / 2;
    B[idx] = (y1 + y2) / 2;
    return 1;
}


int count(double *A, double *B, int *T, int n, int idx)
{
    int res = 0;
    mid(A[0], B[0],A[2*n - 2], B[2*n - 2], 2*n-1, A, B);
    for(int i = 1; i < 2*n -1; i += 2)
    {
        mid(A[i - 1], B[i - 1], A[i + 1], B[i + 1],i, A, B);
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = 1;
        double x1 = A[i];
        double y1 = B[i];
        double x2 = A[i + n];
        double y2 = B[i + n];

        for ( int j = 1; j < n; j++)
        {
            int s = (i + j) % (2*n);
            int t = (i - j);
            if (t < 0) t += 2*n;
            double sx = A[s];
            double sy = B[s];
            double tx = A[t];
            double ty = B[t];
            if (dist(sx, sy, x1, y1) != dist(tx, ty, x1, y1) || dist(sx, sy, x2, y2) != dist(tx, ty, x2, y2))
            {
                tmp = 0;
                break;
            }
        }
        res += tmp;
    }
    T[idx] = res;
    return 1;
}


int main()
{
    int n;
    int t;
    scanf("%d", &t);
    int* T;
    T = malloc(10*sizeof(int));
    for (int i = 0; i < 10; i++) T[i] = 0;
    double *A = malloc(1000000*(sizeof(double)));
    double *B = malloc(1000000*(sizeof(double)));

    for (int i = 0; i < t; i++)
    {
        scanf("%d",&n);
        for (int j = 0; j < n; j++) scanf("%lf %lf", &A[2*j], &B[2*j]);
        count(A,B,T,n,i);
    }
    for (int a = 0; a < t; a++) printf("%d\n", T[a]);

    free(T);
    free(A);
    free(B);
}