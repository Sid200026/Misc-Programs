#include <mpi.h>
#include <stdio.h>

int main()
{
    MPI_Init(NULL, NULL);
    int rank;
    int world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int send_tag = 69;
    int receive_tag = 420;
    int to_send = (rank + 1) % world_size;
    int receive_from = (rank - 1) % world_size;
    MPI_Request send_request, receive_request;
    int received_info;
    MPI_Irecv(&received_info, 1, MPI_INT, receive_from, send_tag, MPI_COMM_WORLD, &receive_request);
    MPI_Isend(&rank, 1, MPI_INT, to_send, send_tag, MPI_COMM_WORLD, &send_request);
    MPI_Wait(&receive_request, MPI_STATUS_IGNORE);
    printf("Rank : %d || Info : %d\n", rank, received_info);
    MPI_Wait(&send_request, MPI_STATUS_IGNORE);
    MPI_Finalize();
}