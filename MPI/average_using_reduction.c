#include <stdio.h>
#include <mpi.h>

#define MASTER 0

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank;
    int world;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world);
    int arr[10];
    if (rank == MASTER)
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = i * 4 + 2 + 5 * i; // Random crap
            printf("%d ", arr[i]);
        }
    }
    int division = 10 / world;
    int buff[division];
    MPI_Scatter(arr, division, MPI_INT, buff, division, MPI_INT, MASTER, MPI_COMM_WORLD);
    int sum = 0;
    for (int i = 0; i < division; i++)
    {
        sum += buff[i];
    }
    int global_sum;
    MPI_Reduce(&sum, &global_sum, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
    {
        double final_avg = global_sum / (double)10;
        printf("\n%2f", final_avg);
    }
    MPI_Finalize();
}