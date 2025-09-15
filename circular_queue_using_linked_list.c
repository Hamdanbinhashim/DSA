#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* rear;
} CircularQueue;

CircularQueue* q;

void createQueue() {
    q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->rear = NULL;
}

void enqueue() {
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (!q->rear) {
        newNode->next = newNode;
        q->rear = newNode;
    } else {
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", data);
}

void dequeue() {
    if (!q->rear) {
        printf("Queue is empty.\n");
        return;
    }
    Node* front = q->rear->next;
    int data = front->data;
    if (q->rear == front) {
        free(front);
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
        free(front);
    }
    printf("Dequeued %d\n", data);
}

void display() {
    if (!q->rear) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->rear->next;
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->rear->next);
    printf("\n");
}

int main() {
    createQueue();
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
