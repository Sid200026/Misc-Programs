#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int MASTER = 0;
    int MAX_SIZE = 256;

    char first_name[MAX_SIZE];
    char last_name[MAX_SIZE];

    if (rank == MASTER)
    {
        scanf("%s", first_name);
        scanf("%s", last_name);
        int i;
        int len = strlen(first_name);
        for (i = strlen(first_name); i - len < strlen(last_name); i++)
        {
            first_name[i] = last_name[i - len];
        }
        first_name[i] = '\0';
        if (strlen(first_name) % 2 != 0)
        {
            int len1 = strlen(last_name);
            last_name[len1] = ' ';
            last_name[len1 + 1] = '\0';
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);
    int division = 1 + strlen(first_name) / world_size;
    char recv_first[division];
    MPI_Scatter(first_name, division, MPI_CHAR, recv_first, division, MPI_CHAR, MASTER, MPI_COMM_WORLD);
    recv_first[division] = '\0';
    int cons = 0;
    for (int i = 0; i < strlen(recv_first); i++)
    {
        char ch = recv_first[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
            cons++;
    }
    int total;
    MPI_Reduce(&cons, &total, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER)
        printf("%d\n", total);
    MPI_Finalize();
}