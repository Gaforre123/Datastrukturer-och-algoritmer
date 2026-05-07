#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef struct Node Node;
struct Node {
    
    int value;
    
    struct Node *left;
    struct Node *right;
    

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

//lägga till värden i trädet
void insert(Node** root, int value) {
    if (*root == NULL){
        Node* newNode = create_node(value);
        *root = newNode;
        return;
    }
    
    //if satser som säger om värdet ska till vänster eller höger
    if (value < (*root)->value) {
        insert(&((*root)->left), value);
    } 
    else if (value > (*root)->value || value == (*root)->value) {
        insert(&((*root)->right), value);
    }
}

//sökfunktion efter värde retunerar adressen till noden med värdet
Node *search(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value == root->value) {
        return root;
    }
    //if satser som säger om man ska leta efter värdet åt höger eller vänster
    if (value < root->value) {
        return search(root->left, value);
    }

    if (value > root->value) {
        return search(root->right, value);
    }
    return NULL;
}
// letar efterminsta noden
Node* minimum(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    //forsätter till nästa left pekare = NULL
    while (root->left != NULL){
       root = root->left;
    }
    return root;
}

//letar efter högsta värde samma som min men åt höger
Node* maximum(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL){
       root = root->right;
    }
    return root;
}
//tar bort noden
Node* delete(Node* root, int value) {
    //Första del är för att hitta noden
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = delete(root->left, value);
    }
    
    else if (value > root->value) {
        root->right = delete(root->right, value);
    }

    else {

        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //flytar mindräe värdet som är udner och flytter så den hamnar över
        // root->right
        Node* temp = minimum(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}
// Nästa mindre värde
Node* predecessor(Node* root, int value) {
    Node* current = root;
    Node* pred = NULL;

    while (current != NULL){
        if (value > current->value){
            pred = current;
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    return pred;
}
// Nästa större värde
Node* successor(Node* root, int value) {
    Node* current = root;
    Node* succ = NULL;

    while (current != NULL) {
        if (value < current->value) {
            succ = current;
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return succ;
}
//För att skriva ut alla värden på trädet
void print(Node* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->value);
    print(root->right);

}
//antal nodar som tillhör trädet
int size(Node* root) {
    if(root == NULL) {
        return 0;
    }

return 1 + size(root->left) + size(root->right);
}

//För att se djupet 
int depth(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    if (leftDepth > rightDepth) {
        return 1 + leftDepth;
    }
    else {
        return 1 + rightDepth;
    }
}

//för att skriva ut värde på Node
void print_node_result(Node* node) {
    if (node != NULL) {
        printf("%d\n", node->value);
    } else {
        printf("NULL\n");
    }
}
int main() {
    Node* root = NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 4);
    insert(&root, 6);

    puts("Initial tree, inorder:");
    print(root);
    puts("\n");

    puts("Test search existing value 8:");
    print_node_result(search(root, 8));

    puts("Test search missing value 99:");
    print_node_result(search(root, 99));

    puts("Test minimum:");
    print_node_result(minimum(root));

    puts("Test maximum:");
    print_node_result(maximum(root));

    puts("Test size:");
    printf("%d\n\n", size(root));

    puts("Test depth:");
    printf("%d\n\n", depth(root));

    puts("Test predecessor of 5:");
    print_node_result(predecessor(root, 5));

    puts("Test successor of 5:");
    print_node_result(successor(root, 5));

    puts("Delete leaf node 4:");
    root = delete(root, 4);
    print(root);
    puts("\n");

    puts("Delete node with one child 2:");
    root = delete(root, 2);
    print(root);
    puts("\n");

    puts("Delete node with two children 5:");
    root = delete(root, 5);
    print(root);
    puts("\n");

    puts("Delete value not in tree 999:");
    root = delete(root, 999);
    print(root);
    puts("\n");

    puts("Final size:");
    printf("%d\n", size(root));

    puts("Final depth:");
    printf("%d\n", depth(root));
    puts("\n\n\n");

    puts("Node L1 & L2");

    Node* L1 = NULL;
    Node* L2 = NULL;

    int arr1[] = {3, 1, 5, 10, 8, 7};
    for (int i = 0; i < 6; i++) {
        insert(&L1, arr1[i]);
    }

    int arr2[] = {5, 2, 9, 6, 1, 2};
    for (int i = 0; i < 6; i++) {
        insert(&L2, arr2[i]);
    }

    printf("L1 minimum: %d\n", minimum(L1)->value);
    printf("L1 maximum: %d\n", maximum(L1)->value);
    
    Node* temp;

    temp = successor(L1, 5);
    printf("Successor of 5: ");
    print_node_result(temp);

    temp = predecessor(L1, 5);
    printf("Predecessor of 5: ");
    print_node_result(temp);

    temp = predecessor(L1, maximum(L1)->value);
    printf("Predecessor of maximum: ");
    print_node_result(temp);
    
    printf("L2 minimum: %d\n", minimum(L2)->value);
    printf("L2 maximum: %d\n", maximum(L2)->value);

    temp = successor(L2, 9);
    printf("Successor of 9: ");
    print_node_result(temp);

    temp = predecessor(L2, 9);
    printf("Predecessor of 9: ");
    print_node_result(temp);

    temp = successor(L2, minimum(L2)->value);
    printf("Successor of minimum: ");
    print_node_result(temp);
    return 0;  
}