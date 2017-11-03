#include <stdio.h>
#include <stdlib.h>

void mkMatrica(int w, int h, int matrica[w][h]){
	int i, j;
	for(i = 0; i < h; i ++)
		for(j = 0; j < w; j ++)
			if(j == i) matrica[i][j] = 1;
			else matrica[i][j] = 0;

}


int main(void){
	int w, h;
	printf("Uneti sirinu i visinu matrice:\n");
	scanf("%i%i", &w, &h);
	

	int matrica[w][h];
	mkMatrica(matrica, &w, &h);


	return 0;
}

