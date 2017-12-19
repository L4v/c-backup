#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array_st{
    int * parray;
    int capacity;
    int filled;
}Array;

void init(Array *a, int s){
    a->parray = NULL;
    a->capacity = s;
    a->filled = 0;
}

void resize(Array *a, int size){
    if(a->parray == NULL)
        a->capacity = 1;
    else
        a->capacity += size;
    a->parray = realloc(a->parray, a->capacity * sizeof(int));
}

void add_item(Array *a, int item){
    if(a->filled == a->capacity)
        resize(a, 1);
    a->parray[a->filled++] = item;
}

int size(Array *a){
    return a->capacity;
}

void print(Array *a){
    int i = 0;
    for (i = 0; i < a->filled; i ++)
        printf("%i ", a->parray[i]);
    puts("");
}

void destroy(Array *a){
    free(a->parray);
    init(a, 0);
}

void remove_item(Array *a, int index){
    
}


int main(void){
    Array arr;
    int i = 0;
    init(&arr, 0);
    for(i = 0; i < 10; i ++)
        add_item(&arr, i);
    print(&arr);
    remove_item(&arr, 2);
    print(&arr);
    return 0;
}
