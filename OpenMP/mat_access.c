#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int ans[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
// Row Major Access
    printf("Row Major\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\nColumn Major\n");
// Column Major Access
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ans[j][i]);
        }
        printf("\n");
    }
}
