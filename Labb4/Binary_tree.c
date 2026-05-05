#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef struct Node Node;
struct Node {
    
    int value;
    
    struct Node *left;
    struct Node *right;
    struct Node *parent;

};

typedef struct {
    Node *root;
} Tree;

//skapa Node
Node *create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    //error hantering
    if(newNode == NULL) {
        printf("Malloc failed\n");
        return NULL;
    }

    //sätt in värde och visar att pekarna inte är fästa till något
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    
    return newNode;
}

void insert(Node** root, int value) {
    Node* newNode = create_node(value);
    if (*root == NULL){
        *root = newNode;
        return;
    }
    
    if (value < (*root)->value) {
        insert(&((*root)->left), newNode);
    }
    else {
        insert(&((*root)->right), newNode);
    }
}
