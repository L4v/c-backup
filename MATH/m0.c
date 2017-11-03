#include <stdio.h>

int main(void){
	int n, i = 0;
	double an, A;
	
	puts("Enter n:");
	scanf("%i", &n);
	
	an = 1;
	for(i = 0; i < n; i ++){
		an = 3 * (2 * an + 1)/(an + 4);
		printf("%lf\n", an);
	}
	
	A = an;
	printf("Limit: %lf\n", A);
	
	return 0;
}
