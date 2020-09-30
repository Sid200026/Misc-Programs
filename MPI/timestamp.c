// #include <stdio.h>
// #include <mpi.h>

// #define MASTER 0
// #define SENDER 0
// #define RECEIVER 1
// #define TAG 1065

// int main(int argc, char **argv)
// {
//     MPI_Init(&argc, &argv);
//     int rank;
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     int num;
//     double total_my_bcast_time = 0.0;
//     if (rank == SENDER)
//     {
//         total_my_bcast_time -= MPI_Wtime();
//         MPI_Send(&rank, 1, MPI_INT, RECEIVER, TAG, MPI_COMM_WORLD);
//         total_my_bcast_time += MPI_Wtime();
//     }
//     else if (rank == RECEIVER)
//     {
//         int info;
//         total_my_bcast_time -= MPI_Wtime();
//         MPI_Recv(&info, 1, MPI_INT, SENDER, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//         total_my_bcast_time += MPI_Wtime();
//     }
//     double timestamp[2];
//     MPI_Gather(&total_my_bcast_time, 1, MPI_DOUBLE, timestamp, 2, MPI_DOUBLE, MASTER, MPI_COMM_WORLD);
//     if (rank == MASTER)
//     {
//         double sum_time = 0.0;
//         for (int i = 0; i < 2; i++)
//         {
//             printf("%2f\n", timestamp[i]);
//             sum_time += timestamp[i];
//         }
//         double avg_time = sum_time / 2.0;
//         printf("Avg Time %2f\n", avg_time);
//     }
//     MPI_Finalize();
// }

#include <stdio.h>
#include <mpi.h>

#define SENDER 0
#define RECEIVER 1
#define TAG 1065
#define ITERS 5

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int num;
    double total_my_bcast_time = 0.0;
    double total_time = 0.0;
    for (int i = 0; i < ITERS; i++)
    {
        if (rank == SENDER)
        {
            total_my_bcast_time -= MPI_Wtime();
            MPI_Send(&total_my_bcast_time, 1, MPI_DOUBLE, RECEIVER, TAG + i, MPI_COMM_WORLD);
            total_my_bcast_time = 0.0;
        }
        else if (rank == RECEIVER)
        {
            double timestamp;
            MPI_Recv(&timestamp, 1, MPI_DOUBLE, SENDER, TAG + i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_my_bcast_time = MPI_Wtime() + timestamp;
            printf("Timestamp for %d : %2f\n", i, total_my_bcast_time);
            total_time += total_my_bcast_time;
            total_my_bcast_time = 0.0;
        }
    }
    // Receiver holds the time summations
    if (rank == RECEIVER)
    {
        double avg_time = total_time / ITERS;
        printf("Average Time : %2f\n", avg_time);
    }
    MPI_Finalize();
    return 0;
}