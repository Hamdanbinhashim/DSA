#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd() {
    int data;
    printf("Enter data to insert at end: ");
    scanf("%d", &data);
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", data);
}

void insertBeginning() {
    int data;
    printf("Enter data to insert at beginning: ");
    scanf("%d", &data);
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode; 
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode; 
    }
    printf("Inserted %d at beginning.\n", data);
}

void insertAfter() {
    int data, key;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter data of the node to insert after: ");
    scanf("%d", &key);

    if (!head) {
        printf("List is empty. Cannot insert after.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    Node* newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    
    printf("Inserted %d after %d.\n", data, key);
}

void deleteBeginning() {
    if (!head) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    int data = temp->data;

    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printf("Deleted %d from beginning.\n", data);
}

void deleteEnd() {
    if (!head) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    int data = head->data

    if (head->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        data = temp->data;
        temp->prev->next = NULL; 
        free(temp); 
    }

    printf("Deleted %d from end.\n", data);
}

void deleteSpecific() {
    int key;
    printf("Enter data of the node to delete: ");
    scanf("%d", &key);

    if (!head) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted node with data %d.\n", key);
}

void display() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int choice;
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert After\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete Specific Node\n");
    printf("7. Display list\n");
    printf("8. Exit\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertAfter(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deleteSpecific(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n");break;
            default: printf("Invalid choice.\n");
        }
    }while (choice!=8);
}
