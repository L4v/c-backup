#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, brPokusaja = 5, broj = 42;
    printf("Zamislio sam neki broj, koji je to broj? (imas %i pokusaja):\n", brPokusaja);
    for(i = 0; i < brPokusaja; i ++){
        printf("Pokusaj br %i:\n", i+1);
        scanf("%i", &n);
        if(n < broj)
            printf("Ispod\n");
        else if(n > broj)
            printf("Iznad\n");
        else if (n == broj){
            printf("Pogodak\n");
            break;
        }
    }


    return 0;
}
