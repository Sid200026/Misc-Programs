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
    MPI_Request request;
    int recv_data;
    if (rank == MASTER)
    {
        for (int i = 1; i < world_size; i++)
        {

            MPI_Irecv(&recv_data, 1, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, &request);
        }
    }
    else
    {
        int send_data = rank * rank + rank;
        MPI_Isend(&send_data, 1, MPI_INT, MASTER, rank, MPI_COMM_WORLD, &request);
    }
    MPI_Wait(&request, MPI_STATUS_IGNORE);
    if (rank == MASTER)
        printf("Received %d", recv_data);

    MPI_Finalize();
    return 0;
}