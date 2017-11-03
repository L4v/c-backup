#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int visina = 10, sirina = 10;
    for(int i = 0; i < visina; i++){
    sleep(1);

        for(int j = 0; j < sirina; j++){
            if(i == j)
                printf(" 1 ");
                else
                printf(" 0 ");
            sleep(1);
            fflush(stdout);
        }//j

        printf("\n");

    }//i

    return 0;
}
