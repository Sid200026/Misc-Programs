#include<omp.h>
#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	bool sieve[n+1];
	sieve[0] = false;
	sieve[1] = false;
	#pragma omp parallel for shared(n)
	for(int i=2; i<=n; i++)
		sieve[i] = true;
	int factor = 2;
	while(factor != n) {
		if(!sieve[factor]) {
			factor++;
			continue;
		}
		#pragma omp parallel for shared(sieve, factor)
		for(int multiplier = 2; multiplier <= n/factor; multiplier++)
			sieve[factor*multiplier] = false;
		factor++;
	}
	for(int i=0; i<=n; i++) {
		if(sieve[i])
			printf("%d\n", i);
	}
	return 0;
}
