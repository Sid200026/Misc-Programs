#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>

#ifndef MASTER
#define MASTER 0
#endif

#ifndef OMP_NUM_THREADS
#define OMP_NUM_THREADS 4
#endif

#ifndef STRING_SIZE
#define STRING_SIZE 256
#endif

int main(int argc, char **argv)
{
    if (!getenv("OMP_NUM_THREADS"))
    {
        omp_set_num_threads(OMP_NUM_THREADS);
    }
    char name[STRING_SIZE];
    char name_rev[STRING_SIZE];
    printf("Siddharth Singha Roy 18BCE1065\n");
#pragma omp parallel private(name)
    {
#pragma omp single copyprivate(name)
        {
            scanf("%s", name);
        }
#pragma omp barrier
#pragma omp for
        for (int i = 0; i < strlen(name); i++)
        {
            name_rev[strlen(name) - i - 1] = name[i];
        }
#pragma omp single
        {
            name_rev[strlen(name)] = '\0';
            printf("Original string : %s\n", name);
            printf("Reversed string : %s\n", name_rev);
        }
    }
    return 0;
}
