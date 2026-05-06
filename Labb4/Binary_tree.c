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

Node* delete(Node* root, int value) {
    //För att hitta noden
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
        
        Node* temp = minimum(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}

Node* predecessor(Node* root, int value) {
    Node* temp = search(root, value);
    if (temp == NULL) {
        return NULL;
    }

    if (temp->left == NULL) {
        return NULL;
    }
    temp = maximum(temp->left);

    return temp;
}

Node* successor(Node* root, int value) {
    Node* temp = search(root, value);
    if (temp == NULL) {
        return NULL;
    }

    if (temp->right == NULL) {
        return NULL;
    }
    temp = minimum(temp->right);

    return temp;
}

void print(Node* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->value);
    print(root->right);

}

int size(Node* root) {
    if(root == NULL) {
        return 0;
    }

return 1 + size(root->left) + size(root->right);
}

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

    return 0;  
}