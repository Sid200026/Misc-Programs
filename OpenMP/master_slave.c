#include<stdio.h>
#include<omp.h>

int main() {
    #pragma omp parallel
    {
        if(omp_get_thread_num() == 0) {
            printf("Master\n");
        } else {
            printf("Slave\n");
        }
    }
}