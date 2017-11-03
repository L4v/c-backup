// Z8
// N!
#include <stdio.h>

int main(){
	
	int n, f = 1;
	
	do{
		puts("Unesite n >= 0 za f(n) = n!: ");
		scanf("%i", &n);
	}while(n < 0);
	
	int i = 0;
	
	for(i = 1; i <= n; i ++)
		f *= i; // f = f * i
		
	printf("f(%i) = %i\n", n, f);
	return 0;
}
