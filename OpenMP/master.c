#include <stdio.h>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
        printf("Start of Secret\n");
#pragma omp master
        {
            printf("Only Master knows the SECRET\n");
        }
        printf("Secret Delivered\n");
    }
}