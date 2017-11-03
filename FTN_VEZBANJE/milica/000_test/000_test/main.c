#include <stdio.h>
#include <stdlib.h>



int main(){
    //%i %d, %s, %c, %f %lf
    int TacanOdgovor = 10;
    int odgovorIgraca;
    printf("Unesi broj:\n");
    scanf("%i", &odgovorIgraca);
    if(odgovorIgraca == TacanOdgovor)
        printf("Tacno");
        else if(odgovorIgraca == 9)
        printf("Blizu si\n");
        else
            printf("Promasio si");

    return 0;
}
