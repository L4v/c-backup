#include <stdio.h>

int main(){
  
 	int n, test = 0;
 	do{
 		puts("Uneti pozitivan broj: ");
 		scanf("%i", &n);
 	}while(n <= 0);
  
  	int i = 0;
  	for(i = 2; i <= n/2; i ++){
  		if(n%i == 0){
  			test ++;
  			printf("Broj %i nije prost\n", n);
  			break;
  		}
  	}
  	if(!test)
  		printf("Broj %i je prost\n", n);
	return 0;
}
