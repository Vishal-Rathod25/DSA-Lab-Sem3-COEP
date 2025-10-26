#include <stdio.h>
#define MAX 10   //number of nodes

//data and link arrays
int data[MAX];
int next[MAX];

// Head pointers for main list and available list
int start = -1;
int avail = 0;


// Function to initialize available list
void initialize() {
    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;   // link all free nodes together
    next[MAX - 1] = -1;     // last node points to -1
    avail = 0;              // available list starts from 0
    start = -1;             // initially no active nodes
}


// Function to get a free node from available list
int getNode() {
    if (avail == -1) {
        printf("\nNo space available (Overflow)!");
        return -1;
    }
    int newNode = avail;
    avail = next[avail]; // move avail pointer to next free node
    return newNode;
}


// Function to release a node back to available list
void freeNode(int node) {
    next[node] = avail;
    avail = node;
}


// Insert element at beginning of list
void insertBeg(int val) {
    int newNode = getNode();
    if (newNode == -1)
        return; // no space

    data[newNode] = val;      // store data
    next[newNode] = start;    // link new node to previous start
    start = newNode;          // make new node the start

    printf("\nInserted %d at the beginning.", val);
}


// Traverse the linked list
void traverse() {
    if (start == -1) {
        printf("\nList is empty!");
        return;
    }

    int ptr = start;
    printf("\nCurrent List: ");
    while (ptr != -1) {
        printf("%d ", data[ptr]);
        ptr = next[ptr];
    }
    printf("\n");
}

// Delete first element
void deleteBeg() {
    if (start == -1) {
        printf("\nList Underflow! (No elements to delete)");
        return;
    }

    int temp = start;
    start = next[start];  // move start to next node
    freeNode(temp);       // release old start node
    printf("\nDeleted first element.");
}

// Main Function (Menu-driven)
int main() {
    int choice, val;
    initialize();

    do {
        printf("\n\n---- Singly Linked List using Array ----");
        printf("\n1. Insert at Beginning");
        printf("\n2. Traverse List");
        printf("\n3. Delete First Element");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertBeg(val);
                break;

            case 2:
                traverse();
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                printf("\nExiting program...");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }
    } while (choice != 4);

    return 0;
}
