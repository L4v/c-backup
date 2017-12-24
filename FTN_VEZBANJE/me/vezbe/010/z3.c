// z3.c REKURZIVNO CIFRE
#include <stdio.h>

int rekt(int num){
    if(num == 0)
        return 0;
    return(num % 10 + rekt(num / 10));
}

int main(void){
    printf("%i\n", rekt(101239));
    return 0;
}
