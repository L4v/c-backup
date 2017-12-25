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

/*char * pop(node_t ** vrh){
    node_t * temp = (*vrh);
    (*vrh) = temp->next;
    char * c = temp->c;
    free(temp);
    return c;
}
*/
char * pop(node_t **vrh) {
    node_t *tmp;
	char * pod;

	if(!(*vrh))
		return '\0';
	//Uzimamo informaciju sa vrha steka
	pod = (*vrh)->c;
	//Sačuvamo element sa vrha liste da ga vratimo posle brisanja
	tmp = *vrh;
	//Prevežemo element sa vrha
	*vrh = tmp->next;
	//obrišemo element sa vrha
	free(tmp);
	//Vratimo sačuvanu vrednost
return pod;
}
//
void print(node_t * head){
    node_t * curr = head;
    while(curr != NULL){
        printf("%s ",curr->c);
        curr = curr->next;
    }
    puts("");
}

void calc(node_t * head){
    int res = 0;
    node_t * curr = head;
    while(curr->next != NULL)
        curr = curr->next;
        puts(curr->c);

}

int main(){
    FILE *input = fopen("input.txt", "r");
    char * c;
    node_t *head = NULL, *curr = NULL;
    head = NULL;
    while(fscanf(input, "%s", c) != EOF && c != "\n"){
        node_t * new = newNode(c);
        if(head == NULL)
            curr = head = new;
        else
            curr = curr->next = new;
        puts(curr->c);
    }
    fclose(input);
    printf("%s\n", pop(&head));
}
