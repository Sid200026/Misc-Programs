#include<stdio.h>
#include<omp.h>

int main() {
	int arr[] = {1,4,5,2,3,5,14,5,11,4,5,5,6,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int odd[n];
	int even[n];
	#pragma omp parallel for
	for(int i=0; i<n; i++)
	{
		odd[i] = 0;
		even[i] = 0;
	}
	#pragma omp parallel for
	for(int i=0; i<n; i++)
	{
		if(arr[i] % 2 == 0)
		{
			even[i] = arr[i];
		} else {
			odd[i] = arr[i];
		}
	}
	int even_sum = 0;
	int odd_sum = 0;
	#pragma omp parallel for reduction(+:even_sum) reduction(+:odd_sum)
	for(int i=0; i<n;i++)
	{
		odd_sum += odd[i];
		even_sum += even[i];
	}
	printf("Odd Sum : %d\nEven Sum : %d\n", odd_sum, even_sum);
	return 0;
}
