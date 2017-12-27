// p1.c STEK POSTFIX
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER 30+1

typedef struct node{
    double val;
    struct node * next;
}node_t;

void init(node_t ** head){
    *head == NULL;
}

node_t *newNode(double val){
    node_t * new = (node_t *)malloc(sizeof(node_t));
    if(new == NULL){
        puts("NOT ENOUGH MEMORY");
        exit(21);
    }
    new->val = val;
    new->next = NULL;
    return new;
}

void add(node_t ** head, node_t * new){
    if(*head == NULL)
        *head = new;
    else{
        new->next = *head;
        *head = new;
    }
}

double pop(node_t ** head){
    if(*head == NULL){
        puts("TRIED POPPING EMPTY STACK");
        exit(22);
    }
    node_t *first = *head;
	double value = first->val;

	*head = first->next;
	free(first);

	return value;
}


void print(node_t * head){
    node_t * curr = head;
    while(curr != NULL){
        printf("%.2lf ",curr->val);
        curr = curr->next;
    }
    puts("");
}

int isNum(char c){
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

void push(node_t ** head, double val){
    node_t * new = newNode(val);
    add(head, new);
}

double calc(FILE *input, node_t **head){
    char buffer[MAX_BUFFER];
    while(fscanf(input, "%s", buffer) != EOF){
        char c = buffer[0];
        if(isNum(c) == 1){
            push(head, atof(buffer));
        }
        else{
            double res;
            char op = c;
            double op2 = pop(head);
            double op1 = pop(head);
            switch(op){
                case '+':res = op1 + op2; break;
                case '-':res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/':
                    if(op2 != 0)
                        res = op1/op2;
                    else
                        puts("Zero divisor");
                    break;
                default:printf("Invalid operator '%c'\n", op);
                exit(31);
            }
            push(head, res);
        }
    }
    return pop(head);
}

FILE *openFile(char *fname, char *mode){
    FILE *fp = fopen(fname, mode);
    if(fp == NULL){
        puts("Can't open file!");
        exit(1);
    }
    return fp;
}

int main(int arg_num, char *args[]){
    if(arg_num != 2){
        printf("USAGE: %s IN_FILE NAME\n", args[0]);
        exit(11);
    }
    char *input_fname = args[1];
    node_t *head;
    init(&head);
    FILE *input = openFile(input_fname, "r");
    double res = calc(input, &head);
    printf("%.2lf\n", res);

    fclose(input);
}
