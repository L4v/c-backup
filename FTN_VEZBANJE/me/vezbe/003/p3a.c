#include <stdio.h>
#define MAX 101

void shortenStr(char str[], int *k){
	int i = 0;
	while(i < *k && str[i] != 0){
		printf("%c", str[i]);
		i ++;
	}
	puts("");
}

int main(void){
	
	int len, i = 0, k;
	char str[MAX];
	puts("Uneti string:");
	scanf("%s", str);
	puts("Uneti k:");
	scanf("%i", &k);
	puts("Skracen string:");
	shortenStr(str, &k);
	
	return 0;
}
