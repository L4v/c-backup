#include <stdio.h>
#include <stdlib.h>



int main()
{
    int x;
    printf("Unesite neki broj\n");
    scanf("%i", &x);
    if(x >= 1 && x <= 3)
        printf("Kvadrat: %i\n", x*x);
    else if(x > 3 && x<= 6)
        printf("Dodaje se 2: %i\n", x+2);
    else if(x > 6)
        printf("Oduzima se 5: %i\n", x-5);
    return 0;
}
