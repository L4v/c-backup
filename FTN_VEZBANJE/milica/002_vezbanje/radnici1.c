#include<stdio.h>
#define MAX 20

typedef struct radnik_st
{
	char ime[MAX];
	char prezime[MAX];
	float plata;
	char zanimanje[30];
}RADNIK;

void smanjenje(RADNIK radnici[], int n, char ime[], double* sm)
{
	FILE *outputfile;
	outputfile =fopen(ime, "w");
	int i;
	for(i=0; i<n; i++)
	{
			*sm += radnici[i].plata - (radnici[i].plata)*0.1;// STAVI RAZLIKU U SM
			radnici[i].plata -= (radnici[i].plata)*0.1;// SMANJI ZAPRAVO PLATU
		
		fprintf(outputfile,"%s %s %d",radnici[i].ime, radnici[i].prezime, radnici[i].plata)
	}

}

void usteda(RADNIK radnici[], int n, double* sm)
{
	int i;
	float usteda;// OVDE KORISTI *sm ZA RACUNANJE, *sm TI JE KOLICINA SMANJENA OD PLATE
	for(i=0; i<n; i++)
	{
		usteda=radnici[i].plata;
	
	}
	printf("usteda je: %f",usteda);

}
	


int main(int narg, char *arg[])
{
	double sm;
	if(arg!=3)
	{
		printf("ne valja");
		return 1;
	}
	
	FILE *inputfile, *outputfile;
	inputfile=fopen(arg[1],"r");
	int brradnika=0;
	RADNIK radnici[MAX];
	
	if(inputfile==NULL)
	{
		printf("nije moguce otvoriti fajl");
		return 1;
	}
	
	while(fscanf(inputfile,"%s %s %f %d",radnici[brradnika].ime, radnici[brradnika].prezime,
										&radnici[brradnika].plata, 
										radnici[brradnika].zanimanje)!=EOF)
	{
		brradnika++;									
	}
	
	fclose(inputfile);
	
	ouputfile=fopen(arg[2],"w");

	smanjenje(radnici, brradnika, arg[2], &sm);	
		
	usteda(radnici, brradnika, &sm)



return 0;
}
