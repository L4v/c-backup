#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_st{
    char str[16];
    struct node_st * next;
}node_t;

void init(node_t ** node){
    *node = NULL;
}

node_t * newNode(char str[]){
    node_t * new = malloc(sizeof(node_t));
    if(new == NULL){
        puts("NOT ENOUGH MEMORY");
        exit(0);
    }
        strcpy(new->str, str);
        new->next = NULL;
    return new;
}

void add(node_t ** head, node_t ** tail, node_t * new){
    if(*tail == NULL)
        *head = *tail = new;
    else{
        (*tail)->next = new;
        *tail = new;
    }
}

void inqueue(node_t ** head, node_t ** tail, char str[]){
    node_t * new = newNode(str);
    add(head, tail, new);
}

void dequeue(node_t ** head, char buffer[]){
    if(*head == NULL){
        puts("TRIED DEQUEUEING EMPTY QUEUE");
        exit(0);
    }
    node_t * temp = *head;
    strcpy(buffer, (*head)->str);
    *head = temp->next;
    free(temp);
}

 void peek(node_t ** head, char buffer[]){
     strcpy(buffer, (*head)->str);
 }

FILE * openFile(char * fname, char * fmode){
    FILE *fp = fopen(fname, fmode);
    if(fp == NULL){
        puts("UNABLE TO OPEN FILE");
        exit(0);
    }
    return fp;
}

int isEmpty(node_t *head){
    if(head == NULL)
        return 1;
    else
        return 0;
}


int main(int argNum, char * args[]){
    if(argNum != 2){
        printf("USAGE: %s <number_of_counters>\n", args[0]);
        exit(0);
    }
    char buffer[16], fname[32];
    int i = 0, counters = atoi(args[1]), served[counters];
    node_t * head, * tail;
    init(&head);
    init(&tail);
    FILE *outputFiles[counters], *inputFile = openFile("clients.txt", "r");
    while(fscanf(inputFile, "%s", buffer) != EOF){
        inqueue(&head, &tail, buffer);
    }

    for(i = 0; i < counters; i ++){
        sprintf(fname,"counter%i.txt", i);
        outputFiles[i] = fopen(fname, "w");
        served[i] = 0;
    }
    i = 0;
    while(!isEmpty(head)){
        if(i == counters)
            i = 0;
        dequeue(&head, buffer);

        fprintf(outputFiles[i], "%s\n", buffer);
        served[i] ++;
        i ++;
    }
    for(i = 0; i < counters; i ++){
        fprintf(outputFiles[i], "---------------\n%i\n", served[i]);
        fclose(outputFiles[i]);
    }
    fclose(inputFile);

    return 0;
}
