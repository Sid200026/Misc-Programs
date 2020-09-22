#include <stdio.h>
#include <mpi.h>

#define MASTER 0

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int num;
    double total_my_bcast_time;
    if (rank == MASTER)
    {
        scanf("%d", &num);
        total_my_bcast_time -= MPI_Wtime();
    }
    MPI_Bcast(&num, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        total_my_bcast_time += MPI_Wtime();
        printf("Time taken %2f\n", total_my_bcast_time);
    }
    printf("Rank : %d || %d\n", rank, num);
    MPI_Finalize();
}