// ARMSTRONGOVI BROJEVI
#include <stdio.h>

int main(){
	int n, temp = 0, temp1 = 0, rez = 0;
	int i = 0;
	for(i = 100; i < 1000; i ++){
		temp1 = i;
		while(temp1 > 0){
			temp = temp1%10;
			rez += temp*temp*temp;
			temp1 /= 10;
		}
		if(i == rez)
			printf("BROJ %i JE ARMSTRONGOV! \n", i);
		rez = 0;
	}
	return 0;
}
