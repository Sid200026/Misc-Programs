#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MASTER 0

//https://mpi.deino.net/mpi_functions/MPI_Gather.html

int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int buff[3];
    for (int i = 0; i < 3; i++)
        buff[i] = i;
    int main_array[(size - 1) * 3];
    MPI_Gather(buff, 3, MPI_INT, main_array, (size - 1) * 3, MPI_INT, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
        for (int i = 0; i < (size)*3; i++)
            printf("%d\n", main_array[i]);
    MPI_Finalize();
}