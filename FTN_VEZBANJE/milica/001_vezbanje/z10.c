// Z10
// PROST
#include <stdio.h>

int main(){

	int i, n, ne_prost = 0;
	do{
		puts("Unesite broj veci od 0 ");
		scanf("%i", &n);
	}while(n <= 0);
	
	for(i = 2; i <= n/2; i ++)
		if(n % i == 0){
			ne_prost = 1;
			printf("Broj %i nije prost \n", n);
			break;
		}
	if(!ne_prost)
		printf("Broj %i je prost \n", n);

	return 0;
}
