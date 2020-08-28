#include<omp.h>
#include<stdio.h>
int main(){
     if (omp_get_num_threads() == 1)
    {
        omp_set_num_threads(4);
    }
	int a[10],b[10];
	for(int j=0;j<10;j++){
		a[j]=j+1;
		b[j]=j+1;
	}
	int i=0;
	int sum=0;
	#pragma omp parallel for reduction(+:sum)
	for(i=0;i<10;i++){
		sum=sum+a[i]+b[i];

		printf("%d\n", sum);
	}
	printf("sum= %d\n",sum);
	return 0;
}
