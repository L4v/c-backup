#include <stdio.h>

int main(){
	int i = 0, a, b, mRez=0;
	
	puts("Uneti a i b:");
	scanf("%i%i", &a, &b);
	// MNOZENJE
	for(i = 0; i < b; i ++)
		mRez += a;
	// DELJENJE
	i = 0;
	while(a >= b){
		a -= b;
		i++;
	}
	printf("CELOBROJNI REZULTATI:\n\ta * b = %i\n\ta / b = %i\n", mRez, i);
}
