#include<mpi.h>
#include<stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int rank;
    int arr[100];

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) {
        int send_only = 53;
        MPI_Send(arr, send_only, MPI_INT, 1, 45, MPI_COMM_WORLD);
    } else {
        int copy[100]; // Extra size is allocated
        MPI_Status status;
        MPI_Recv(copy, 100, MPI_INT, 0, 45, MPI_COMM_WORLD, &status);
        int received;
        MPI_Get_count(&status, MPI_INT, &received);
        printf("Received %d numbers from rank %d", received, status.MPI_SOURCE);
    }

    MPI_Finalize();
}