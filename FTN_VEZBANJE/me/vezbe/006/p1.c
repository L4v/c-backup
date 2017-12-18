#include <stdio.h>
#include <stdlib.h>

int main(){
	int *br;
	br = malloc(sizeof(int));
	
	puts("Uneti ceo broj:");
	scanf("%i", br);
	
	printf("Ucitan je: %i\n", *br);
	
	free(br);
	
	return 0;
}
