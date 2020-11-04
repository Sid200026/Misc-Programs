#include <stdio.h>
#include <mpi.h>

#ifndef MASTER
#define MASTER 0
#endif

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int ele[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int div = 5;
    int recv[div];
    MPI_Scatter(ele, div, MPI_INT, recv, div, MPI_INT, MASTER, MPI_COMM_WORLD);
    int sum = 0;
    for (int i = 0; i < div; i++)
    {
        sum += recv[i];
    }
    int global_sum;
    MPI_Reduce(&sum, &global_sum, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        printf("%d", global_sum);
    }
    MPI_Finalize();
    return 0;
}