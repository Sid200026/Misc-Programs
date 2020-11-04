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

    int num;
    if (rank == MASTER)
    {
        scanf("%d", &num);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Bcast(&num, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
    printf("%d\n", num);
    MPI_Finalize();
}