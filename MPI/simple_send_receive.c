#include <stdio.h>
#include <mpi.h>

#ifndef MASTER
#define MASTER 0
#endif

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int world_size;
    int rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (rank == MASTER)
    {
        for (int i = 1; i < world_size; i++)
        {
            int recv_data;
            MPI_Recv(&recv_data, 1, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, NULL);
            printf("Received %d from core %d\n", recv_data, i);
        }
    }
    else
    {
        int send_data = rank * rank + rank;
        MPI_Send(&send_data, 1, MPI_INT, MASTER, rank, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}