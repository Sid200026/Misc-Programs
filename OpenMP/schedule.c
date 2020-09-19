#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);
#pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", i, omp_get_thread_num()); // The extra 2 iteration is assigned to thread 0
    }
    printf("\n\n");
#pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", i, omp_get_thread_num());
    }
    printf("\n\n");
#pragma omp parallel for schedule(guided, 2)
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", i, omp_get_thread_num());
    }
}