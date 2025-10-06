#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    int size;
    int allocated;
    int id;
    struct Block* next;
} Block;

Block* createBlock(int size) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    if (newBlock == NULL) {
        printf("Failed to allocate memory for a new block");
        return 0;
    }
    newBlock->size = size;
    newBlock->allocated = 0;
    newBlock->id = -1;
    newBlock->next = NULL;
    return newBlock;
}

void appendBlock(Block** head, int size) {
    Block* newBlock = createBlock(size);
    if (*head == NULL) {
        *head = newBlock;
    } else {
        Block* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBlock;
    }
}

void freeList(Block* head) {
    Block* current = head;
    Block* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

Block* initializeMemory(const int blockSizes[], int m) {
    Block* head = NULL;
    for (int i = 0; i < m; i++) {
        appendBlock(&head, blockSizes[i]);
    }
    return head;
}

void printBlocks(Block* head, const char* title) {
    printf("\n--- %s Memory Status ---\n", title);
    Block* temp = head;
    if (temp == NULL) {      
        printf("The memory list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("Block size: %d | Allocated: %s", temp->size, temp->allocated ? "Yes" : "No");
        if (temp->allocated)
            printf(" | Process ID: %d", temp->id);
        printf("\n");
        temp = temp->next;
    }
    printf("----------------------------------------\n");
}

// a) Worst-fit allocation
void worstFit(Block* head, const int processes[], int n) {
    printf("\n--- Running Worst-Fit Allocation ---\n");
    for (int i = 0; i < n; i++) {
        Block* temp = head;
        Block* worstBlock = NULL;
        int processSize = processes[i];
        
        while (temp != NULL) {
            if (!temp->allocated && temp->size >= processSize) {
                if (worstBlock == NULL || temp->size > worstBlock->size) {
                    worstBlock = temp;
                }
            }
            temp = temp->next;
        }

        if (worstBlock != NULL) {
            worstBlock->allocated = 1;
            worstBlock->id = i + 1;
            printf("Process %d (size %d) allocated to Block size %d.\n", i + 1, processSize, worstBlock->size);
        } else {
            printf("Process %d (size %d) Not Allocated.\n", i + 1, processSize);
        }
    }
}

// b) Best-fit allocation
void bestFit(Block* head, const int processes[], int n) {
    printf("\n--- Running Best-Fit Allocation ---\n");
    for (int i = 0; i < n; i++) {
        Block* temp = head;
        Block* bestBlock = NULL;
        int processSize = processes[i];
        
        while (temp != NULL) {
            if (!temp->allocated && temp->size >= processSize) {
                if (bestBlock == NULL || temp->size < bestBlock->size) {
                    bestBlock = temp;
                }
            }
            temp = temp->next;
        }
        
        if (bestBlock != NULL) {
            bestBlock->allocated = 1;
            bestBlock->id = i + 1;
            printf("Process %d (size %d) allocated to Block size %d.\n", i + 1, processSize, bestBlock->size);
        } else {
            printf("Process %d (size %d) Not Allocated.\n", i + 1, processSize);
        }
    }
}

// c) First-fit allocation
void firstFit(Block* head, const int processes[], int n) {
    printf("\n--- Running First-Fit Allocation ---\n");
    for (int i = 0; i < n; i++) {
        Block* temp = head;
        int processSize = processes[i];
        
        while (temp != NULL) {
            if (!temp->allocated && temp->size >= processSize) {
                temp->allocated = 1;
                temp->id = i + 1;
                printf("Process %d (size %d) allocated to Block size %d.\n", i + 1, processSize, temp->size);
                break;
            }
            temp = temp->next;
        }
        
        if (temp == NULL) {
            printf("Process %d (size %d) Not Allocated.\n", i + 1, processSize);
        }
    }
}

// Main menu driver
int main() {
    const int blockSizes[] = {100, 500, 200, 300, 600};
    const int processes[] = {212, 417, 112, 426};
    int m = sizeof(blockSizes) / sizeof(blockSizes[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    Block* head = NULL;
    int choice;
    printf("\n============================================\n");
    printf("  Memory Allocation Simulation Menu\n");
    printf("  (Blocks: 100, 500, 200, 300, 600)\n");
    printf("  (Processes: 212, 417, 112, 426)\n");
    printf("============================================\n");
    printf("1. Run First-Fit\n");
    printf("2. Run Best-Fit\n");
    printf("3. Run Worst-Fit\n");
    printf("4. Exit\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Reset memory for a clean run before each algorithm
        if (head != NULL) {
            freeList(head);
            head = NULL;
        }
        head = initializeMemory(blockSizes, m);

        switch (choice) {
            case 1:
                firstFit(head, processes, n);
                printBlocks(head, "First-Fit Results");
                break;
            case 2:
                bestFit(head, processes, n);
                printBlocks(head, "Best-Fit Results");
                break;
            case 3:
                worstFit(head, processes, n);
                printBlocks(head, "Worst-Fit Results");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        
    } while (choice != 4);
    return 0;
}
