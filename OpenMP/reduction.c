#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int sum = 0;
#pragma omp parallel for shared(arr) // shared is not required
    {
        for (int i = 0; i < 6; i++)
        {
            sum += arr[i]; // May produce a wrong result
        }
    }
    printf("%d\n", sum);

    sum = 0;
#pragma omp parallel for shared(arr) // shared is not required
    {
        for (int i = 0; i < 6; i++)
        {
#pragma omp critical
            sum += arr[i]; // Will produce the correct result
        }
    }
    printf("%d\n", sum);

    // The above method can be replaced with a reduction

    sum = 0;

#pragma omp parallel for shared(arr) reduction(+: sum)
    {
        for (int i = 0; i < 6; i++)
        {
            sum += arr[i]; // Correct result
        }
    }
    printf("%d", sum);
}