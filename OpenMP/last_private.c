#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 1;
#pragma omp parallel for lastprivate(i)
    for(i=0; i<10; i++)
    {
        i = i + 1;
        printf("%d\n", i);
    }
    printf("\n\n");
#pragma omp parallel
    {
        printf("%d\n", i); // Value of i is 10
    }
}