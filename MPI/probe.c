#include<mpi.h>
#include<stdio.h>

int main() {
    int rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) {
        int buff[100];
        int to_send = 53;
        MPI_Send(buff, to_send, MPI_INT, 1, 32, MPI_COMM_WORLD);
    } else {
        MPI_Status status;
        MPI_Probe(0,32, MPI_COMM_WORLD, &status);
        int size;
        MPI_Get_count(&status, MPI_INT, &size);
        int arr[size];
        MPI_Recv(arr, size, MPI_INT, 0, 32, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
}