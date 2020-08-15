#include <stdio.h>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
        printf("Start of Secret\n");
#pragma omp critical
        {
            printf("SECRET\n");
        }
        printf("Secret Delivered\n");
    }
}