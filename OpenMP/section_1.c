#include<omp.h>
#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int array[5]={10,20,30,40,50};
    int i;
    int result;
    #pragma omp parallel sections
    {
	#pragma omp section
	#pragma omp parallel for
	for(int i=0;i<5;i++)
    	{
        	result = arr[i]+array[i];
        	printf("Value post addition%d\n",result);
    	}
    	#pragma omp section
    	#pragma omp parallel for
    	for(int i=0;i<5;i++)
    	{
        	result = arr[i]*array[i];
        	printf("Value post multiplication %d\n",result);
    	}
    }
}
