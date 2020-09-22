#include <stdio.h>
#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int rank, world;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world);
    int value = rank + 3 * 2 + rank * rank * 4; // Super random crap
    int buffer[world];
    MPI_Allgather(&value, 1, MPI_INT, buffer, 1, MPI_INT, MPI_COMM_WORLD);
    for (int i = 0; i < world; i++)
    {
        printf("Rank : %d || %d\n", rank, buffer[i]);
    }
    MPI_Finalize();
}