#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to search for a specific element in the linked list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current; // Element found
        }
        current = current->next;
    }

    return NULL; // Element not found
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some elements at the beginning of the linked list
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 9);

    // Print the linked list
    printf("Linked List: ");
    printLinkedList(head);

    int key = 5;
    struct Node* result = search(head, key);

    if (result != NULL) {
        printf("%d found in the linked list.\n", key);
    } else {
        printf("%d not found in the linked list.\n", key);
    }

    return 0;
}
