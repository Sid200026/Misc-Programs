#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 0;
#pragma omp parallel
    {
        x = x + 1;
        printf("%d", x); // Produces a read-write conflict
    }
    printf("\n\n");
    int y = 0;
#pragma omp parallel
    {
#pragma omp critical
        {
            y = y + 1;
            printf("%d", y); // Won't produce a race condition
        }
    }
}