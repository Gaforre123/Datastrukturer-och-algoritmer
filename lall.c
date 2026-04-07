#include <stdio.h>



struct node {
    int data;
    struct node *next;
};

struct node *prepend(struct node *head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    return new_node;
};

struct node *append(struct node *head, int value){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;

    return head;
}

int list_length(struct node *head){
    struct node *current = head;
    int length = 0;

    while (current != NULL) {
        current = current->next;
        length++;
        
    }
    return length;
};


int find(struct node *head, int value){
    struct node *current = head;
    int position = 0;

    while (current != NULL){
        if (current->data == value) {
            return position;
        }
        else {
            current = current->next;
            position++;
        }
    }
    return -1;
};

void print_list(struct node *head){
    struct node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
};

int main() {
    
    struct node *head = NULL;
    struct node *secondHead = NULL;

    prepend(head,4);
    prepend(head,5);
    prepend(head,10);
    printf(list_length(head));
    
    
 

}
