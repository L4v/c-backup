// z2.c STABLO AUTOMOBILI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_st{
    char  naziv[32];
    int kub, god;
    struct node_st * levo, * desno;
}node_t;

node_t * newNode(char * naziv, int kub, int god){
    node_t * new = malloc(sizeof(node_t));
    if(new == NULL){
        puts("NEMA DOVOLJNO MEMORIJE");
        exit(0);
    }
    strcpy(new->naziv, naziv);
    new->kub = kub;
    new->god = god;
    new->levo = new->desno = NULL;
    return new;
}

void insert(node_t ** root, node_t * new){
    if(*root == NULL)
        *root = new;
    else if(new->naziv < (*root)->naziv)
        insert(&(*root)->levo, new);
    else if((*root)->naziv < new->naziv)
        insert(&(*root)->desno, new);
}

FILE *otvori(char * fileIme, char * mod){
    FILE *f = fopen(fileIme, mod);
    if(f == NULL){
        puts("NEMOGUCE OTVORITI FILE");
        exit(0);
    }
    return f;
}

void ucitaj(FILE * f, node_t ** root){
    node_t * new;
    char naziv[32];
    int kub, god;
    while(fscanf(f, "%s %i %i", naziv, &kub, &god) != EOF){
        new = newNode(naziv, kub, god);
        insert(root, new);
    }
}

void ispisMarka(node_t *root, char *naziv) {
	if (root != NULL) {
		if (strncmp(root->naziv, naziv, strlen(naziv)) == 0) {
			printf("%s %d %d\n", root->naziv, root->kub, root->god);
		}else if(naziv > root->naziv)
            ispisMarka(root->levo, naziv);
        else if(naziv < root->naziv)
            ispisMarka(root->desno, naziv);
        else
            printf("NE POSTOJI MODEL:%s\n", naziv);

	}
}

void prikaz(node_t * root){
    if(root != NULL){
        printf("%s %i %i\n", root->naziv, root->kub, root->god);
        if(root->levo != NULL){
            puts("LEVO");
            prikaz(root->levo);
        }
        if(root->desno != NULL){
            puts("DESNO");
            prikaz(root->desno);
        }
    }
}

int main(){
    FILE * ulaz = otvori("auto.txt", "r");
    node_t * root;
    root = NULL;
    ucitaj(ulaz, &root);
    //prikaz(root);
    ispisMarka(root, "Zastava");
}
