#include <stdio.h>
#include <mpi.h>

#define MASTER_RANK 1
#define TAG 69

int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == MASTER_RANK)
    {
        int info = 420;
        for (int i = 0; i < size; i++)
        {
            if (i == rank)
                continue;
            MPI_Send(&info, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
        }
    }
    else
    {
        int info;
        MPI_Recv(&info, 1, MPI_INT, MASTER_RANK, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%d\n", info);
    }
    MPI_Finalize();
}