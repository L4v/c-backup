//naucnici
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
	char ime[16], prezime[16], oblast[16];
	int radovi;
}naucnik;

void prerada(char ul[], char izl[], int * br){
	naucnik naucnici[MAX];
	FILE *ulaz, *izlaz;
	ulaz = fopen(ul, "r");
	izlaz = fopen(izl, "w");
	int i = 0, len;
	//
	while(fscanf(ulaz, "%s%s%s%i", naucnici[i].ime, naucnici[i].prezime, naucnici[i].oblast, &(naucnici[i].radovi)) != EOF)
		i ++;
	//
	len = i;
	for(i = 0; i < len; i ++){
		if(naucnici[i].radovi > *br)
			fprintf(izlaz, "%s %s %s %i\n", naucnici[i].ime, naucnici[i].prezime, naucnici[i].oblast, naucnici[i].radovi);
		
	}
}

int main(int argB, char * argC[]){
	if(argB != 4)
		return 0;
	else{
		int br = atoi(argC[3]);
		prerada(argC[1], argC[2], &br);
	}
	
	return 0;
}
