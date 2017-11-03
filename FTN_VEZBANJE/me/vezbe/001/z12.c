#include <stdio.h>
#include <math.h>

int main(){

	double pi;
	double i = 0;
	for(i = 1; i < 1000; i ++)
		pi += 1/(i*i);
	pi *= 6;
	pi = sqrt(pi);
	printf("APROKSIMACIJA PI : %lf \n", pi);
	return 0;
}
