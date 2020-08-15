#include<stdio.h>
#include<omp.h>

int main() {
    int n;
    scanf("%d",&n);
    int thread_id = 0;
    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num(); // Compulsory if we use private
        printf("%d\n", thread_id+n);
        if(thread_id == 0) { // Only master thread has thread ID as 0
            // Only the master thread ie. the thread that is executing the entire program will execute this
            printf("Total Threads : %d\n", omp_get_num_threads());
        }
    }
    printf("%d", thread_id);
}