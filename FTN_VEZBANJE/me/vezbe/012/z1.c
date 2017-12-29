// z1.c STABLO
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st{
    int val;
    struct node_st * left, * right;
}node_t;

node_t * newNode(int val){
    node_t * new = malloc(sizeof(node_t));
    if(new == NULL){
        puts("NOT ENOUGH MEMORY");
        exit(0);
    }
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

void insert(node_t ** leaf, int val){
    if(*leaf == NULL)
        *leaf = newNode(val);
    else if(val < (*leaf)->val)
        insert(&(*leaf)->left, val);
    else if(val > (*leaf)->val)
        insert(&(*leaf)->right, val);
}

node_t * search(node_t * leaf, int val){
    if(leaf != NULL){
        if(val == leaf->val)
            return leaf;
        else if(val < leaf->val)
            return search(leaf->left, val);
        else if(val > leaf->val)
            return search(leaf->right, val);
    }else{
        printf("NODE %i DOES NOT EXIST\n",  val);
        return NULL;
    }
}

void display(node_t * root){
    printf("%i ", root->val);
    if(root->left != NULL)
        display(root->left);
    if(root->right != NULL)
        display(root->right);
}

void leftToRight(node_t * root){
    if(root != NULL){
        leftToRight(root->left);
        printf("%i ", root->val);
        leftToRight(root->right);
    }
}

void rightToLeft(node_t * root){
    if(root != NULL){
        rightToLeft(root->right);
        printf("%i ", root->val);
        rightToLeft(root->left);
    }
}

int main(){
    node_t *root;
    root = newNode(10);
    int i;
    insert(&root, 6);
    insert(&root, 14);
    insert(&root, 5);
    insert(&root, 11);
    insert(&root, 8);
    insert(&root, 18);
    display(root);
    puts("");
    leftToRight(root);
    puts("");
    rightToLeft(root);
    puts("");
}
/*
			       10
			     /    \
			    6      14
			   / \    /  \
			  5   8  11  18
*/
