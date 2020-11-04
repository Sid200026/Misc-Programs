#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <mpi.h>

#ifndef TOTAL_SEATS
#define TOTAL_SEATS 20
#endif

#ifndef MASTER
#define MASTER 0
#endif

int randomAssignment()
{
    return rand() % TOTAL_SEATS;
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world_size;
    srand(time(0));
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    bool seats[TOTAL_SEATS];
    memset(seats, false, TOTAL_SEATS);
    int wrongly_assigned = 0;
    if (rank == MASTER)
    {
        int seatAssignment = randomAssignment();
        if (seatAssignment != 0)
            wrongly_assigned++;
        seats[seatAssignment] = true;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    for (int i = 1; i < TOTAL_SEATS; i++)
    {
        int seatAssignment;
        if (i % world_size == 0)
        {
            // Core 0
            if (!seats[i])
            {
                seatAssignment = i;
            }
            else
            {
                seatAssignment = randomAssignment();
                while (seats[seatAssignment])
                {
                    seatAssignment = randomAssignment();
                }
                printf("Person %d assigned seat %d\n", i, seatAssignment);
                wrongly_assigned++;
            }
        }
        else
        {
            // Core 1
            if (!seats[i])
            {
                seatAssignment = i;
            }
            else
            {
                int seatAssignment = randomAssignment();
                while (seats[seatAssignment])
                {
                    seatAssignment = randomAssignment();
                }
                printf("Person %d assigned seat %d\n", i, seatAssignment);
                wrongly_assigned++;
            }
        }
        MPI_Bcast(&seatAssignment, 1, MPI_INT, i % world_size, MPI_COMM_WORLD);
        seats[seatAssignment] = true;
    }
    int incorrectly_counter;
    MPI_Reduce(&wrongly_assigned, &incorrectly_counter, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        printf("%d", wrongly_assigned);
    }
    MPI_Finalize();
    return 0;
}