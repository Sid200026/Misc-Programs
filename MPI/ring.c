#include <mpi.h>
#include <stdio.h>

int main()
{
    MPI_Init(NULL, NULL);

    int rank;
    int world_size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int to_send = (rank + 1) % world_size;
    int to_receive = (rank + world_size - 1) % world_size;

    if(rank == 0) {
        int num = 0;
        MPI_Send(&num, 1, MPI_INT, to_send, 13, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, to_receive, 13, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received %d from rank %d\n", num, to_receive);

    } else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, to_receive, 13, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received %d from rank %d\n", num, to_receive);
        num++;
        MPI_Send(&num, 1, MPI_INT, to_send, 13, MPI_COMM_WORLD);
        num++;
    }

    MPI_Finalize();
}