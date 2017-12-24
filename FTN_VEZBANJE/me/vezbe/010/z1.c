// z1.c REKURZIVNA FIBONACCI
#include <stdio.h>

int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return(fib(n-1) + fib(n - 2));
}

int main(){
    printf("%i\n", fib(14));
    return 0;
}
