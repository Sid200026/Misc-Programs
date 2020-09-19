#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(4);
    int num;
#pragma omp parallel private(num)
    {
#pragma omp single copyprivate(num)
        {
            scanf("%d", &num);
        }
        num = num + 1;
        printf("%d ", num);
    }
}