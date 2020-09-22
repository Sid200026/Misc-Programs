#include <stdio.h>
#include <mpi.h>

#define MASTER 1

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world);
    int info[] = {1, 2, 3, 4, 5, 6};
    int total_size = sizeof(info) / sizeof(info[0]);
    int division = total_size / (world); // Exclude the master
    int recv[division];
    MPI_Scatter(info, division, MPI_INT, recv, division, MPI_INT, MASTER, MPI_COMM_WORLD);
    for (int i = 0; i < division; i++)
    {
        printf("Rank : %d || %d\n", rank, *(recv + i));
    }
    MPI_Finalize();
}

/*
Rank : 1 || 4
Rank : 1 || 5
Rank : 1 || 6
Rank : 0 || 1
Rank : 0 || 2
Rank : 0 || 3
*/