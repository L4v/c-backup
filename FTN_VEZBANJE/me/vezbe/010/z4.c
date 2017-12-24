// z4.c REKURZIVNO NZD
#include <stdio.h>

int nzd(int x, int y){
    if(x == 0)
        return y;
    else return (nzd(y%x, x));
}

int main(void){
    printf("%i\n", nzd(105, 50));
    return 0;
}
