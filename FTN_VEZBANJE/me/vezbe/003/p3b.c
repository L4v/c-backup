#include <stdio.h>
#define MAX 101

int getLen(char str[]){
	int i = 0;
	while(str[i] != 0)
		i ++;
	return i;
}

int main(void){
	int k, i;
	char str[MAX];
	puts("Unesite string:");
	scanf("%s", str);
	puts("Unesite k:");
	scanf("%i", &k);
	puts("Skraceni:");
	if(getLen(str) >= k)
		puts(str + getLen(str) - k);
	else
		puts(str);
	
	return 0;
}
