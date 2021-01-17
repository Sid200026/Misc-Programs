#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>

#ifndef TOTAL_THREADS
#define TOTAL_THREADS 128
#endif

#ifndef TOTAL_SIZE
#define TOTAL_SIZE 64
#endif

int randomAssignment()
{
    srand(time(0));
    return rand();
}

int main()
{
    if (!getenv("OMP_NUM_THREADS"))
    {
        omp_set_num_threads(TOTAL_THREADS);
    }
    clock_t t;
    int tid;
    int insertionCount = 0;
    int extractionCount = 0;
    int queue[64];
    int currentLength = 0;
    t = clock();
#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        bool addOperation = false;
        if (tid % 2 == 0)
        {
            addOperation = true;
        }
        else
        {
            addOperation = false;
        }
        int element;
#pragma omp critical
        {
            if (addOperation)
            {
                element = randomAssignment();
                queue[currentLength++] = element;
                insertionCount++;
                if (insertionCount == 5)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 5 insertion = %f\n", time_taken);
                }
                if (insertionCount == 10)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 10 insertion = %f\n", time_taken);
                }
                if (insertionCount == 50)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 50 insertion = %f\n", time_taken);
                }
            }
            else
            {
                if (currentLength != 0)
                    element = queue[currentLength];
                extractionCount++;
                if (extractionCount == 5)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 5 extraction = %f\n", time_taken);
                }
                if (extractionCount == 25)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 25 extraction = %f\n", time_taken);
                }
                if (extractionCount == 50)
                {
                    clock_t t1;
                    t1 = clock() - t;
                    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
                    printf("Execution time of 50 extraction = %f\n", time_taken);
                }
            }
        }
    }
    return 0;
}