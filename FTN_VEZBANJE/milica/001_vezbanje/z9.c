// Z9
// N i q, od 2 do N deljivo sa q
#include <stdio.h>

int main(){
	
	int i, N, q;
	
	do{
		puts("Unesite brojeve N i q: ");
		scanf("%i%i", &N, &q);
	}while(N <= 0 || q <= 0);
	
	i = 0;
	
	for(i = 2; i <= N; i ++)
		if(i%q==0)
			printf("%i ", i);
	printf("\n");
	
	
	return 0;
}
