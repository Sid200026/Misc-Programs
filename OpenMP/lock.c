#include <omp.h>
#include <stdio.h>

int main()
{
    int num = 5;
    omp_lock_t lock;
    omp_init_lock(&lock);
#pragma omp parallel
    {
        omp_set_lock(&lock);
        num += 1;
        printf("%d %d\n", num, omp_get_thread_num());
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
}