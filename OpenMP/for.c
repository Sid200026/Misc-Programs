#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    /*
    The code below represents how to use for loop without the for directive
    */

    int i = 0;
// 4 threads will be created
// ID : 0 will execute i=0-2
// ID : 1 will execute i=3-5
// ID : 2 will execute i=6-8
// ID : 3 will execute i=9-11
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int i = thread_id * 3; i <= thread_id * 3 + 2 && i<=10; i++)
        {
            printf("Thread : %d || %d\n", thread_id, i);
        }
    }
    printf("\n\n");
    /*
    Using the for directive
    */
    #pragma omp parallel for
    for (int i = 0; i <= 10; i++)
    {
        int thread_id = omp_get_thread_num();
        printf("Thread : %d || %d\n", thread_id, i);
    }
}