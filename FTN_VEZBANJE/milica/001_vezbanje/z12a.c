// PI POD A
// z12a.c
#include <stdio.h>
#include <math.h>

int main(){

 	int n;
 	double pi = 0, i;
	do{
		puts("Uneti koliko clanova: ");
		scanf("%i", &n);
	}while(n <= 0);
	
	for	(i = 1; i <= n; i ++)
		pi += (1/pow(i, 2));

	pi *= 6;
	pi = sqrt(pi);
	printf("Aproksimacija pi:= %0.8lf\n", pi); 

	return 0;
}
