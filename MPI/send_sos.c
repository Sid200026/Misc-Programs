#include <mpi.h>
#include <stdio.h>

int main()
{
    MPI_Init(NULL, NULL);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    {
        char temp[4] = {'s', 'o', 's'};
        MPI_Send(temp, 4, MPI_CHAR, 1, 433, MPI_COMM_WORLD);
    } else {
        char buff[4];
        MPI_Recv(buff, 4, MPI_CHAR, 0, 433, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%s", buff);
    }
    MPI_Finalize();
}