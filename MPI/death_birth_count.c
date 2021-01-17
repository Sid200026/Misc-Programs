#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <mpi.h>

#ifndef MASTER
#define MASTER 0
#endif

int randomAssignment(int rank)
{
    srand(time(0));
    return rand() % 100 + rank;
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int birth = randomAssignment(rank);
    int death = randomAssignment(rank * world_size + rank + world_size);
    int global_birth[world_size], global_death[world_size];
    MPI_Gather(&birth, 1, MPI_INT, global_birth, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
    MPI_Gather(&death, 1, MPI_INT, global_death, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        for (int i = 0; i < world_size; i++)
        {
            printf("District %d\n", i);
            printf("Total Deaths  : %d\n", global_death[i]);
            printf("Total Births  : %d\n", global_birth[i]);
        }
    }
    MPI_Finalize();
    return 0;
}