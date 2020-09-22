#include <mpi.h>
#include <stdio.h>
#include <math.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void substring(char s[], char sub[], int p, int l)
{
    int c = 0;
    while (c < l)
    {
        sub[c] = s[p + c];
        c++;
    }
    sub[c] = '\0';
}

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);
    int rank;
    int size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("Rank : %d || Processor : %s\n", rank, processor_name);
    char message[] = "Hello how are you. Let's connect over LinkedIn";
    char sub_message[100];
    int total_size = sizeof(message) / sizeof(message[0]);
    int start_tag = 100;
    int current = 0;
    int width = 10;
    if (rank == 0)
    {
        // Send the total number of iterations
        int iterations = ceil(total_size / (double)width);
        MPI_Send(&iterations, 1, MPI_INT, 1, 10, MPI_COMM_WORLD);
        while (current < total_size)
        {
            substring(message, sub_message, current, min(total_size - current, width));
            // 1 is added to the size of the data so that the last character ie. \0 is included
            MPI_Send(sub_message, min(total_size - current, width) + 1, MPI_CHAR, 1, start_tag, MPI_COMM_WORLD);
            current += width;
            start_tag += 1;
        }
    }
    else
    {
        int iterations;
        MPI_Recv(&iterations, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < iterations; i++)
        {
            MPI_Status status;
            MPI_Probe(0, start_tag, MPI_COMM_WORLD, &status);
            int msg_recv_size;
            MPI_Get_count(&status, MPI_CHAR, &msg_recv_size);
            char recv_msg[msg_recv_size];
            MPI_Recv(recv_msg, msg_recv_size, MPI_CHAR, 0, start_tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received : %s\n", recv_msg);
            start_tag++;
        }
    }
    MPI_Finalize();
}