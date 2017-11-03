// Z11
// TROCIFREN ABC
// ARMSTRONG = AAA BBB CCC
#include <stdio.h>

int main(){// 123
	
	int i, n, temp, temp_i, a = 0;
	
	for( i = 100; i < 1000; i ++){
		temp_i = i;// temp_i CUVA VREDNOST i
		while(temp_i > 0){
			temp = temp_i % 10;
			a += temp * temp * temp;
			temp_i /= 10;
		}
		if( a == i)
			printf("A:%i ", i);
		a = 0;
	}
	
	printf("\n");

	return 0;
	}
