#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* q;

void createQueue() {
    q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
}

void enqueue() {
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", data);
}

void dequeue() {
    if (!q->front) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    if (!q->front)
        q->rear = NULL;
    free(temp);
    printf("Dequeued %d\n", data);
}

void display() {
    if (!q->front) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createQueue();
    int choice;
    while (1) {
        printf("\n--- Queue Menu ---\n");
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
