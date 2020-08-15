#include <stdio.h>
#include <omp.h>

int main()
{
    static int i;
    #pragma omp threadprivate(i)
    printf("Assigning Thread ID\n");
    #pragma omp parallel 
        i = omp_get_thread_num();
    printf("Completed Assigning Thread ID\n");
    #pragma omp parallel
        printf("ID : %d\n", i);
}