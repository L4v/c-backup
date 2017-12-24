// z2.c FIBONACCI MENU
#include <stdio.h>

int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return(fib(n-1) + fib(n - 2));
}

void print(int n){
    if(n <= 0)
        return;
    else{
        printf("%i\n", fib(n));
        return print(n-1);
    }
}

int main(){
    char c = 0;
    while(c != 27){
        puts("Odaberite ESC izlaz ili 1 za fib");
        c = getchar();
        getchar();
        if(c == '1')
            print(5);
    }
    return 0;
}
