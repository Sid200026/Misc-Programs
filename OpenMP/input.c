#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#ifndef TOTAL_THREADS
#define TOTAL_THREADS 4
#endif

int main()
{
    if (!getenv("OMP_NUM_THREADS"))
    {
        omp_set_num_threads(TOTAL_THREADS);
    }
    int num;
#pragma omp parallel private(num)
    {
#pragma omp single copyprivate(num)
        {
            scanf("%d", &num);
        }
#pragma omp barrier
        printf("%d\n", num);
    }
    return 0;
}