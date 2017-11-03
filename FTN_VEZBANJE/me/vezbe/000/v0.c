// ZADATAK 7
#include <stdio.h>

int main(){

	int i, a, b, mRez = 0;
	puts("Uneti a i b: ");
	scanf("%i%i", &a, &b);
	//Mnozenje
	for(i = 0; i < b; i ++)
		mRez += a;
	//Deljenje
	i = 0;
	while(a > 0){
		a -= b;
		i ++;
	}
	printf("Celobrojni rezultati:\n\n\ta * b = %i\n\ta / b = %i\n\n", mRez, i);
	return 0;
}
