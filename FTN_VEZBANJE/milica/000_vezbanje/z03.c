#include <stdio.h>

int main(){
	int n = 5;
	scanf("%i", &n);
	while(n == 0){
		scanf("%i", &n);
	}
	puts("BRAVO");
	return 0;
}

