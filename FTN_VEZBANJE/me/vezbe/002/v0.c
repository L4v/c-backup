#include <stdio.h>

void unosNiza(char niz[], int *n, int  i){
	for( i = 0; i < *n; i++)
			scanf(" %c", &niz[i]);
}
void ispisNiza(char niz[], int *n, int i){
	for( i = 0; i < *n; i++)
		printf("%c", niz[i]);
	printf("\n");
}
void transNiza(char niz[], int *n, int i){
	for( i = 0; i < *n; i ++){
		if(!(niz[i] >= '0' && niz[i] <= '9'))
			niz[i] = '#';
	}
	
}

int main(){	
	int n, i = 0;
	puts("Unesite duzinu niza:");
	scanf("%i", &n);
	char niz[n];
	puts("Unesite niz:");
	unosNiza(niz, &n, i);
	puts("Ispis niza:");
	ispisNiza(niz, &n, i);
	transNiza(niz, &n, i);
	puts("Ispis transformisanog niza:");
	ispisNiza(niz, &n, i);
		
	return 0;
}
