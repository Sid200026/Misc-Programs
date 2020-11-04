#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>

#ifndef TOTAL_SEATS
#define TOTAL_SEATS 20
#endif

#ifndef TOTAL_THREADS
#define TOTAL_THREADS 4
#endif

int randomAssignment()
{
    return rand() % TOTAL_SEATS;
}

int main(int argc, char **argv)
{
    omp_set_num_threads(TOTAL_THREADS);
    srand(time(0));

    bool seats[TOTAL_SEATS];
    memset(seats, false, TOTAL_SEATS);
    int wrongly_assigned = 0;
#pragma omp parallel
    {
#pragma omp master
        {
            int seatAssigned = randomAssignment();
            if (seatAssigned != 0)
            {
                wrongly_assigned++;
            }
            seats[seatAssigned] = true;
        }
#pragma omp barrier
#pragma omp for ordered
        for (int i = 1; i < TOTAL_SEATS; i++)
        {
            int seatAssigned;
#pragma omp critical
            {
                if (!seats[i])
                {
                    seats[i] = true;
                }
                else
                {
                    seatAssigned = randomAssignment();
                    while (seats[seatAssigned])
                    {
                        seatAssigned = randomAssignment();
                    }
                    printf("Person %d assigned %d\n", i, seatAssigned);
                    seats[seatAssigned] = true;
                    wrongly_assigned++;
                }
            }
        }
    }
    float correctly_seated = 100 * (TOTAL_SEATS - wrongly_assigned) / (float)TOTAL_SEATS;
    float incorrectly_seated = 100 - correctly_seated;
    printf("Correctly : %f\n", correctly_seated);
    printf("Incorrectly : %f\n", incorrectly_seated);
    return 0;
}