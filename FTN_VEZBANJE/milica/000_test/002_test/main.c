#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int n, res = 0;
    printf("Koliko brojeva:\n");
    scanf("%i", &n);

    for(int i = n; i > 0; i --)
        res += i;

    printf("Rezultat: %i\n", res);
    return 0;
}
