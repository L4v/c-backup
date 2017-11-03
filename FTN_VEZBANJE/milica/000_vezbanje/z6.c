#include <stdio.h>

int main(){
	int n, rez = 0;
	puts("Uneti n: ");
	scanf("%i", &n);
	int i = 0;
	for(i = 1; i <= n; i ++)
		rez += i;
	
	printf("Rezultat: %i\n", rez);

	return 0;
}
