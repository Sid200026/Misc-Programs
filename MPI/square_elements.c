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
    int ele[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(ele) / sizeof(int);
    int scatter_size = size / world_size;
    int recv[scatter_size];
    MPI_Scatter(ele, scatter_size, MPI_INT, recv, scatter_size, MPI_INT, MASTER, MPI_COMM_WORLD);
    for (int i = 0; i < scatter_size; i++)
    {
        recv[i] *= recv[i];
    }
    int fin[size];
    MPI_Gather(recv, scatter_size, MPI_INT, fin, scatter_size, MPI_INT, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", fin[i]);
        }
    }
    MPI_Finalize();
    return 0;
}