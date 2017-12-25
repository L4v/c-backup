// p1.c STEK POSTFIX
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char * c;
    struct node * next;
}node_t;

node_t * newNode(char * c){
    node_t * new = malloc(sizeof(node_t));
    new->c = c;
    new->next = NULL;
    return new;
}

char * pop(node_t ** head){
    node_t * curr = (*head);
    while(curr->next != NULL)
        curr = curr->next;
    return curr->next->c;
}

void print(node_t * head){
    node_t * curr = head;
    while(curr != NULL){
        printf("%s ",curr->c);
        curr = curr->next;
    }
    puts("");
}

int main(){
    FILE *input = fopen("input.txt", "r");
    char * c;
    node_t *head = NULL, *curr = NULL;
    while(fscanf(input, "%s", c) != EOF){
        node_t * new = newNode(c);
        if(head == NULL)
            curr = head = new;
        else
            curr = curr->next = new;
        puts(curr->c);
    }
    
    fclose(input);
}
