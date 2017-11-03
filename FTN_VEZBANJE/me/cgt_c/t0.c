#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int push(char *);
char *pop(void);

int main(void){
	
	int zn;
	char red[80 + 1];

	while(1){
		printf("Komanda (u, p ili i) + Return: ");
		gets(red);
		switch(red[0]){
			case 'u':
			case 'U':
			printf("Poruka : ");
			gets(red);
			if(push(red) != 0)
			printf("Stek je pun\n");break;
			case 'p':
			case 'P':
				printf("%s\n", pop());
				break;
			case 'i':
			case 'I':
				return 0;
}
}

	return 0;
}
