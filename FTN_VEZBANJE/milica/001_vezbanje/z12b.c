#include <stdio.h>

int main(){

	int n, i;
	double pi = 1;
	
	do{
		puts("Unesite pozitivan prirodan broj konjine ");
		scanf("%i", &n);
	}while(n <= 0);

	for( i = 1; i <= n; i ++){
		if (i % 2 != 0){
			puts("NEPARAN");
			pi -= (double)(1/(2*i + 1));
			printf("PI %lf\n", pi);
		}else if(i % 2 == 0){
				puts("PARAN");
			pi += (double)1/((2*i + 1));
			printf("PI %lf\n", pi);
			}
		}
	
	printf("Aproksimacija pi:= %0.8lf \n", pi);
	pi *= 4;
	printf("Aproksimacija pi:= %0.8lf \n", pi);

	return 0;
}
