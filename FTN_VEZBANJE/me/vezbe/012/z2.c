// z2.c STABLO AUTOMOBILI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_st{
    char * naziv;
    int kub, god;
    struct node_st * levo, * desno;
}node_t;

node_t * newNode(char * naziv, int kub, int god){
    node_t * new = malloc(sizeof(node_t));
    if(new != NULL){
        puts("NEMA DOVOLJNO MEMORIJE");
        exit(0);
    }
    new->naziv = naziv;
    new->int = kub;
    new->god = god;
    new->levo = new->desno = NULL;
    return new;
}

void insert(node_t ** root, node_t * new){
    if(*root == NULL)
        *root = new;
    else if((*root)->god > new->god)
        insert((*root)->left, new);
    else if(&(*root)->god < new->god)
        insert(&(*root)->right, new);
}

int main(){

}
