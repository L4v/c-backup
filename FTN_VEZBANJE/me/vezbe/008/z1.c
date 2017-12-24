// z1.c 19.12.2017
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
}node_t;

void append(node_t *head, int val){
    node_t *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = malloc(sizeof(node_t));
    curr->next->val = val;
    curr->next->next = NULL;


}

void push(node_t ** head, int val){
    node_t * new;
    new = malloc(sizeof(node_t));

    new->val = val;
    new->next = *head;
    *head = new;

}

int pop(node_t ** head){
    int ret = -1;
    node_t * next = NULL;

    if(*head == NULL)
        return -1;
    next = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next;

    return ret;
}

void print(node_t *head){
    node_t *curr = head;

    while(curr != NULL){
        printf("%i ", curr->val);
        curr = curr->next;
    }
    puts("");
}

int main(void){
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL)
        return 1;
    head->val = 1;
    head->next = NULL;
    print(head);
    int i = 0;
    for(i = 0; i < 10; i ++)
        push(&head, i);
    print(head);
    return 0;
}
