#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

int count_nodes() {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}


void create_node(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = val;
    new_node->next = new_node;
    new_node->prev = new_node;
    head = new_node;
    printf("Node with data %d created as the list head.\n", val);
}

void insert_at_beginning(int val) {
    if (head == NULL) {
        create_node(val);
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = val;

    struct node* last = head->prev; 
    new_node->next = head;
    new_node->prev = last;

    head->prev = new_node;
    last->next = new_node; 

    
    head = new_node;
    printf("Node with data %d inserted at the beginning.\n", val);
}


void insert_at_end(int val) {
    if (head == NULL) {
        create_node(val);
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = val;

    struct node* last = head->prev;
   
    new_node->next = head;
    new_node->prev = last;

    
    head->prev = new_node; 
    last->next = new_node;

    printf("Node with data %d inserted at the end.\n", val);
}


void insert_at_position(int val, int pos) {
    int size = count_nodes();

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position. Current list size is %d.\n", size);
        return;
    }

    if (pos == 1) {
        insert_at_beginning(val);
        return;
    }
    if (pos == size + 1) {
        insert_at_end(val);
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = val;

    struct node* current = head;
    
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    
    new_node->next = current->next;
    new_node->prev = current;

    
    current->next->prev = new_node; 
    current->next = new_node;       

    printf("Node with data %d inserted at position %d.\n", val, pos);
}


void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct node* to_delete = head;
    struct node* last = head->prev;

    if (head->next == head) { 
        head = NULL;
        free(to_delete);
        printf("The only node deleted. List is now empty.\n");
        return;
    }

    
    head = head->next;

    
    head->prev = last;  
    last->next = head;  

   
    free(to_delete);
    printf("Node deleted from the beginning.\n");
}


void delete_at_end() {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct node* to_delete = head->prev; 

    if (head->next == head) { 
        head = NULL;
        free(to_delete);
        printf("The only node deleted. List is now empty.\n");
        return;
    }

    struct node* new_last = to_delete->prev; 

    
    new_last->next = head; 
    head->prev = new_last; 

    
    free(to_delete);
    printf("Node deleted from the end.\n");
}


void delete_at_position(int pos) {
    int size = count_nodes();

    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if (pos < 1 || pos > size) {
        printf("Invalid position. List size is %d.\n", size);
        return;
    }

    if (pos == 1) {
        delete_at_beginning();
        return;
    }
    if (pos == size) {
        delete_at_end();
        return;
    }

    struct node* current = head;
    
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }
    

    struct node* before = current->prev;
    struct node* after = current->next;

    
    before->next = after;
    after->prev = before;

    
    free(current);
    printf("Node deleted from position %d.\n", pos);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("\nCircular Doubly Linked List (Forward): ");
    do {
        printf(" %d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (Back to Head: %d)\n", head->data);
}


void search_node(int val) {
    if (head == NULL) {
        printf("List is empty. Search failed.\n");
        return;
    }

    struct node* temp = head;
    int pos = 1;
    do {
        if (temp->data == val) {
            printf("Node with data %d found at position %d.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Node with data %d not found in the list.\n", val);
}



void main() {
    int choice, value, position;

    printf("--- Circular Doubly Linked List Menu ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at specific Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from specific Position\n");
    printf("7. Display List\n");
    printf("8. Search Node\n");
    printf("9. Exit\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_at_beginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(value, position);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search_node(value);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=9);
}
