#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int w, h;
	printf("Uneti visinu i sirinu matrice:\n");
	scanf("%i%i", &w, &h);
	int matrica[w][h];
	for(int i = 0; i < h; i ++)
		for(int j = 0; j < w; j ++)
			if(j == i)
			    matrica[j][i]=1;
			else if (j == (w-1-i))
			    matrica[j][i]=1;
			else
			    matrica[j][i]=0;

	for (int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
		    printf(" %i ", matrica[j][i]);
		    nanosleep((const struct timespec[]){{0,10000000L}}, NULL);
		    fflush(stdout); 
		}
		printf("\n");
	}
	return 0;
}
