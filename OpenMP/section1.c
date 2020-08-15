#include <stdio.h>
#include <omp.h>

int fun1()
{
    return 2;
}

int fun2()
{
    return 3;
}

int main()
{
    omp_set_num_threads(4);
    int a, b; // Declared as shared variable because if declared private then
    // suppose thread 0 assigned a to 1. No other thread will have access to this value

#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("%d | Executing 1\n", tid);
                a = fun1();
            }
            #pragma omp section
            {
                printf("%d | Executing 2\n", tid);
                b = fun2();
            }
        }
        // Implicit barrier is present here to ensure that sections are executed first
        #pragma omp single
            printf("Answer %d", a + b);
    }
}