#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#ifndef MASTER
#define MASTER 0
#endif

#ifndef ARR_SIZE
#define ARR_SIZE 6
#endif

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = i + i;
    }
    int recv[ARR_SIZE / world_size];
    MPI_Scatter(arr, ARR_SIZE / world_size, MPI_INT, recv, ARR_SIZE / world_size, MPI_INT, MASTER, MPI_COMM_WORLD);
    for (int i = 0; i < ARR_SIZE / world_size; i++)
    {
        printf("%d ", *(recv + i));
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}