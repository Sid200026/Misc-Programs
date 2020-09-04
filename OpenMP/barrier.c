#include<stdio.h>
#include<omp.h>

int main() {
	int num;
	#pragma omp parallel shared(num)
	{
		#pragma omp master
		{
			num = 4;
		}
		#pragma omp barrier
		printf("%d\n", num);
	}
}
