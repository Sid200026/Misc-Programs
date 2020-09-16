#include<mpi.h>
#include<stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int count = 0;
    int turns = 0;
    int partner_rank = (rank+1)%2;
    while(turns != 10) {
        if(rank == turns%2) 
        {
            turns++;
            MPI_Send(&turns, 1, MPI_INT, partner_rank, 62, MPI_COMM_WORLD);
            printf("Send Ping from %d\n", rank);
        }
        else {
            MPI_Recv(&turns, 1, MPI_INT, partner_rank, 62, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received Pong from %d\n", partner_rank);
        }
    }
    MPI_Finalize();
}