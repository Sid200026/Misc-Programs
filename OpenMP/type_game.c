//  A small game is played between 5 players. The players are asked to type a 6 letter word in English in parallel.
//  The letters are numbered as A=1, B=2,….,Z=26. The sum of the numbers corresponding to the letters in the word is counted.
//  All the players are given three parallel chances. The cumulative sum of words is computed after the
// fifth chance and the player with highest cumulative sum is declared as winner. Implement a solution for this using OpenMP.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>

#ifndef TOTAL_THREADS
#define TOTAL_THREADS 5
#endif

#ifndef MAX
#define MAX 26
#endif

int randomAssignment()
{
    return rand();
}

int main()
{
    srand(time(0));
    if (!getenv("OMP_NUM_THREADS"))
    {
        omp_set_num_threads(TOTAL_THREADS);
    }
    int maxsum = 0;
    int tidmax = 0;
    char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};
#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int total_cost = 0;
        for (int i = 0; i < 5; i++)
        {
            char word[6];

            for (int i = 0; i < 6; i++)
            {
                word[i] = alphabet[randomAssignment() % MAX];
            }
            printf("6 letter word for player %d is %s\n", tid, word);

            int cost = 0;
            for (int j = 0; j < 6; j++)
            {
                cost += (int)word[j] - (int)'a' + 1;
            }
            total_cost += cost;
        }
#pragma omp critical
        {
            if (total_cost > maxsum)
            {
                maxsum = total_cost;
                tidmax = tid;
            }
        }
    }
    printf("Player %d won with score %d\n", tidmax, maxsum);
    return 0;
}