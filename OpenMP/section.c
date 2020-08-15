#include<stdio.h>
#include<omp.h>

int main() {
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp sections
        {
            // 3 threads will execute although we have 4 threads.
            #pragma omp section
            {
                printf("%d | Executing 1\n", tid);
            }
            #pragma omp section
            {
                printf("%d | Executing 2\n", tid);
            }
            #pragma omp section
            {
                printf("%d | Executing 3\n", tid);
            }
        }
    }
}