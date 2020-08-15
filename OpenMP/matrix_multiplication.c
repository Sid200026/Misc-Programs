#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int ans[3][3];
    clock_t start = clock();
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 3; i++)
        {
            int res = 0;
            int k, j;
            for (k = 0; k < 3; k++)
            {
                for (j = 0; j < 3; j++)
                {
                    res += arr[i][j] * arr[j][i];
                }
                ans[i][k] = res;
            }
        }
    }
    clock_t end = clock();
    clock_t diff = end - start;
    double time_taken = ((double)diff) / CLOCKS_PER_SEC;
    printf("Execution Time : %f seconds\n", time_taken);

// Print the matrix
#pragma omp parallel
#pragma omp single
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
}

/*
Since we assumed the matrix size as 3, the above code can be changed to used sections instead

for (int i = 0; i < 3; i++)
    {
        int res = 0;
        int k, j;
        for (k = 0; k < 3; k++)
        {
            for (j = 0; j < 3; j++)
            {
                res += arr[i][j] * arr[j][i];
            }
            ans[i][k] = res;
        }
    }

REPLACED BY

#pragma omp parallel sections
{
    #pragma omp section
    {
        int i=0;
        int res = 0;
        int k, j;
        for (k = 0; k < 3; k++)
        {
            for (j = 0; j < 3; j++)
            {
                res += arr[i][j] * arr[j][i];
            }
            ans[i][k] = res;
        }
    }

    #pragma omp section
    {
        int i=1;
        int res = 0;
        int k, j;
        for (k = 0; k < 3; k++)
        {
            for (j = 0; j < 3; j++)
            {
                res += arr[i][j] * arr[j][i];
            }
            ans[i][k] = res;
        }
    }

    #pragma omp section
    {
        int i=2;
        int res = 0;
        int k, j;
        for (k = 0; k < 3; k++)
        {
            for (j = 0; j < 3; j++)
            {
                res += arr[i][j] * arr[j][i];
            }
            ans[i][k] = res;
        }
    }
}

*/