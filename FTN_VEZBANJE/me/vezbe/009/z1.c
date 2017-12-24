// z1.c JEDNOSTRUKO SPREGNUTA
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node * next;
}node_t;

node_t *init(char c){
    node_t *node = malloc(sizeof(node_t));
    node->c = c;
    node->next = NULL;
    return node;
}

void add(node_t ** head, char c1){
    node_t * temp = (*head);
    node_t * new = init(c1);
    while(temp != NULL){
        if(temp->c == c1)
            return;
        temp = temp->next;
    }
    if(*head == NULL || (*head)->c > new->c){
        new->next = *head;
        *head = new;
    }else{
    temp = (*head);
        while(temp->next != NULL && temp->next->c < new->c)
            temp = temp->next;
    new->next = temp->next;
    temp->next = new;
    }
}

void change(node_t ** head, char c1, char c2){
    node_t * temp = (*head);
    while(temp != NULL){
        if(temp->c == c1)
            temp->c = c2;
        temp = temp->next;
    }
}

void print(node_t * head){
    node_t * temp = head;
    while(temp != NULL){
        printf("{%c}", temp->c);
        temp = temp->next;
    }
    puts("");
}

int main(void){
    node_t * head = init('\0');
    char i;
    for(i = 'a'; i < 'z'; i ++)
        add(&head, i);
    print(head);
    add(&head, 'A');
    print(head);
    change(&head, 'A', 'd');
    print(head);
  return 0;
}
