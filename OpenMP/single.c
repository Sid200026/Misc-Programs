#include<stdio.h>
#include<omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Top Secret\n");
        }
        // We have an implicit barrier here to ensure that the single thread is executed before continuing
        printf("Don't tell it to anyone\n");
    }
}