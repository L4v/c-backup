#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct darray_st{
	int *parray;
	int filled;
	int capacity;
}Array;

void init_ar(Array *a){
	a->parray = NULL;
	a->filled = 0;
	a->capacity = 0;
}

void resize_ar(Array *a){
	if(a->parray == NULL)
		a->capacity = 1;
	else
		a->capacity *= 2;
	a->parray = realloc(a->parray, a->capacity * sizeof(int));
}

void add_item(Array *a, int val){
	if(a->filled == a->capacity)
		resize_ar(a);

	a->parray[a->filled] = val;
	a->filled ++;
}

int size_ar(Array *a){
	return a->capacity;
}

void print_ar(Array *a){
	int i;
	printf("[");
	for(i = 0; i < a->filled; i ++){
		if(i > 0)
			printf(", ");

		printf("%i", a->parray[i]);
	}
	printf("]\n");
}

void rm_item_index(Array **a, int i){
		Array *temp;
		temp->parray = malloc((size_ar(*a)-1)*sizeof(int));
		temp->capacity = (size_ar(*a)-1)*sizeof(int);
		temp->filled = (*a)->filled - 1;
		if(i != 0)
			memcpy(temp->parray, (*a)->parray, (i-1)*sizeof(int));
		if(i != (*a)->capacity -1)
			memcpy(temp->parray + (i*sizeof(int)), (*a)->parray + i + 1, (size_ar(*a) - i - 1)*sizeof(int));
		free((*a)->parray);
		(*a)->parray = temp->parray;
}

void rm_item_val(Array *a, int item){
	int i = 0;
	for( i = 0; i < a->filled; i ++)
		if(a->parray[i] == item)
			rm_item_index(&a, i);

				printf("Removed item: %i\n", item);
				if(a->capacity >= 2*(a->filled)){
					resize_ar(a);
					puts("Resized array");
					printf("New size: %i, of that, used: %i \n", a->capacity, a->filled);
				}
}

void destroy_ar(Array *a){
	free(a->parray);
	init_ar(a);
}

int main(){
	int i = 0;
	Array a;

	init_ar(&a);
	for(i = 0; i < 99; i ++)
		add_item(&a, i);
	print_ar(&a);
	printf("Velicina:%i\n", size_ar(&a));

	add_item(&a, 42);
	print_ar(&a);
	printf("Velicina:%i\n", size_ar(&a));
	printf("Zauzeto:%i\n", a.filled);

	rm_item_val(&a, 2);

	destroy_ar(&a);
	printf("Velicina:%i\n", size_ar(&a));
	print_ar(&a);
	return 0;
}
