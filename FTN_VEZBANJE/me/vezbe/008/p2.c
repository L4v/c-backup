// z1.c 19.12.2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array_st{
    int *array;
    int cap;
    int fill;
}Array;

void init(Array *a, int cap){
    a->array = NULL;
    a->cap = cap;
    a->fill = 0;
}

void resize(Array *a, int size){
    if(a->cap == 0)
        a->cap = 1;
    else
        a->cap += size;
    a->array = realloc(a->array, a->cap * sizeof(int));
}

void delete(Array *a){
    free(a->array);
    init(a, 0);
}

void add_item(Array *a, int item){
    if(a->fill == a->cap)
        resize(a, 1);
    a->array[a->fill++] = item;
}

void print(Array *a){
    int i = 0;
    for(i = 0; i < a->fill; i ++)
        printf("%i ", a->array[i]);
    puts("");
}

void rm_item(Array *a, int item){
    int i = 0;
    for(i = 0; i < a->fill; i ++)
        if(a->array[i] == item)
            break;
    Array temp;
    init(&temp, 0);
    temp.array = realloc(temp.array, (a->fill - 1)*sizeof(int));
    memmove(temp.array, a->array, i * sizeof(int));
    memmove(temp.array + i, a->array + i + 1, (a->cap - i)*sizeof(int));
    free(a->array);
    resize(a, -1);
    a->fill --;
    a->array = temp.array;
}


int main(void){
    Array a;
    int i = 0;
    init(&a, 0);
    for(i = 0; i < 10; i ++)
        if(i != 5)
            add_item(&a, i);
        else
            add_item(&a, i);
    print(&a);
    
    print(&a);

    return 0;
}
