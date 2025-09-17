#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Function to check if deque is full
int isFull() {
    return ( (front == 0 && rear == SIZE - 1) || (front == rear + 1) );
}

// Function to check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue at rear
void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;
    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

// Enqueue at front
void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0)
        front = SIZE - 1;
    else
        front--;
    deque[front] = value;
    printf("%d inserted at front\n", value);
}

// Dequeue from front
void dequeueFront() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    int value = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1)
        front = 0;
    else
        front++;
    printf("%d removed from front\n", value);
}

// Dequeue from rear
void dequeueRear() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    int value = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0)
        rear = SIZE - 1;
    else
        rear--;
    printf("%d removed from rear\n", value);
}

// Get front element
void getFront() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Front element: %d\n", deque[front]);
}

// Get rear element
void getRear() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Rear element: %d\n", deque[rear]);
}

// Display the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Enqueue Rear\n");
        printf("2. Enqueue Front\n");
        printf("3. Dequeue Rear\n");
        printf("4. Dequeue Front\n");
        printf("5. Display Front\n");
        printf("6. Display Rear\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 3:
                dequeueRear();
                break;
            case 4:
                dequeueFront();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                displayDeque();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
