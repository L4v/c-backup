#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argNum, char * args[]){
    if(argNum != 2){
        printf("UPOTREBA: %s ulazna_dat br_poena\n", args[0]);
        exit(1);
    }


    return 0;
}
