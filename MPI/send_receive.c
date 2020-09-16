#include <mpi.h>
#include <stdio.h>

int main()
{
    MPI_Init(NULL, NULL);

    int rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) { // Sender
        int number = 10;
        MPI_Send(&number, 1, MPI_INT, 1, 69, MPI_COMM_WORLD);
    } else {
        int number;
        MPI_Recv(&number, 1, MPI_INT, 0, 69, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received : %d", number);
    }

    MPI_Finalize();
}