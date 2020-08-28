#include<stdio.h>
#include<omp.h>
#include<math.h>
#define INT_MAX 9999999
#define INT_MIN -999999

int main() {
	int n;
	scanf("%d", &n);
	int marks[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", (marks+i));
	}
	int max = INT_MIN;
	int min = INT_MAX;
	int sum = 0;
	#pragma omp parallel for shared(marks) reduction (+:sum)
	for(int i=0; i<n; i++)
	{
		int current = marks[i];
		sum+=current;
		#pragma omp critical
		{
			if(current>max)
				max = current;
			if(current < min)
				min = current;
		}
	}
	double average = sum/(double)n;
	double sqDiff = 0;
	#pragma omp parallel for reduction (+:sqDiff)
	for(int i=0; i<n; i++)
	{
		sqDiff += pow(average-(double)marks[i],2);
	}
	double sd = sqrt(sqDiff/n);
	printf("Maximum is : %d\n", max);
	printf("Minimum is : %d\n", min);
	printf("Mean is : %2f\n", average);
	printf("Standard Deviation is : %2f\n", sd);
	return 0;
}
