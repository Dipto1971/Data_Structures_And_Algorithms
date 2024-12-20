#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    struct Node *next;
}

struct node* createLinkedList(int n){
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    for(i=1; i<=n; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){
            cout << "Memory allocation failed" << endl;
            break;
        }
        cout << "Enter the value of Node " << i << " -> ";
        cin >> newNode -> value;
        newNode -> next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
}

int main () {
    struct Node * head;
    struct Node * Node2;
    struct Node * Node3;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    Node2 = (struct Node*)malloc(sizeof(struct Node));
    Node3 = (struct Node*)malloc(sizeof(struct Node));

    head->value = 1;
    head->next = Node2;

    Node->value = 2;
    Node->next = Node3;

    Node->value = 3;
    Node->next = NULL;
}