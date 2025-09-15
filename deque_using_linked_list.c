#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* d;

void createDeque() {
    d = (Deque*)malloc(sizeof(Deque));
    d->front = d->rear = NULL;
}

void insertFront() {
    int data;
    printf("Enter data to insert at front: ");
    scanf("%d", &data);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = d->front;
    if (!d->front)
        d->rear = newNode;
    else
        d->front->prev = newNode;
    d->front = newNode;
    printf("Inserted %d at front.\n", data);
}

void insertRear() {
    int data;
    printf("Enter data to insert at rear: ");
    scanf("%d", &data);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = d->rear;
    if (!d->rear)
        d->front = newNode;
    else
        d->rear->next = newNode;
    d->rear = newNode;
    printf("Inserted %d at rear.\n", data);
}

void deleteFront() {
    if (!d->front) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = d->front;
    int data = temp->data;
    d->front = temp->next;
    if (d->front)
        d->front->prev = NULL;
    else
        d->rear = NULL;
    free(temp);
    printf("Deleted from front: %d\n", data);
}

void deleteRear() {
    if (!d->rear) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = d->rear;
    int data = temp->data;
    d->rear = temp->prev;
    if (d->rear)
        d->rear->next = NULL;
    else
        d->front = NULL;
    free(temp);
    printf("Deleted from rear: %d\n", data);
}

void display() {
    if (!d->front) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = d->front;
    printf("Deque: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createDeque();
    int choice;
    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
