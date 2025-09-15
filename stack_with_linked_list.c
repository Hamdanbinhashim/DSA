#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push() {
    int data;
    printf("Enter data to push: ");
    scanf("%d", &data);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", data);
}

void pop() {
    if (!top) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = top;
    int data = temp->data;
    top = temp->next;
    free(temp);
    printf("Popped %d\n", data);
}

void display() {
    if (!top) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = top;
    printf("Stack:\n");
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
