#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 10;

#pragma omp parallel private(i)
    {
        printf("%d\n", i); // Garbage Value
    }
    printf("\n\n");
#pragma omp parallel for firstprivate(i)
    {
        for (int x=0; x < 5; x++)
        {
            i = x;
            printf("%d\n", i);
        }
    }
    printf("\n\n");
#pragma omp parallel
    {
        printf("%d\n", i); // Value of i doesn't change here
    }
}