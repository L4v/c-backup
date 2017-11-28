//z4.c BROJ RECI
#include <stdio.h>
#include <string.h>

int isword(char *c){
	if((*c >= 'A' && *c <= 'Z') || (*c>='a' && *c<='z') || (*c>='0' && *c<='9'))
		return 1;
	else
		return 0;
}

void broj(char dat[]){
	FILE *f;
	f  = fopen(dat, "r");
	char str[100], tmp, max;
	int brReci = 0, maxLen = 0;
	fgets(f, "%s", str);
	puts(str);
	
	
	fclose(f);
}

int main(int argNum, char *argC[]){
	if(argNum != 2)
		puts("Neadekvatan broj argumenata");
	else{
		broj(argC[1]);
	}
	return 0;
}
