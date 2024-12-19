#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

void linkedlistTraversal(struct Node *ptr){ //Time Complexity: O(n)
    while(ptr != NULL){
        printf("%d\n", ptr -> value);
        ptr = ptr -> next;
    }
}

int main(){
    // Linked list implemeneation only using head pointer

    struct Node *cur; //initialization
    int n,i;
    printf("How many Nodes you want to create? -> ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        cur = (struct Node*)malloc(sizeof(struct Node)); //For each Node, allocating a memory space
        printf("Enter the value of Node %d -> ", i+1);
        scanf("%d", &cur -> value); //picking the value from console
        cur -> next = NULL; 
        if(head == NULL){ //for the first Node of Linkelist chain head will be NULL
            head = cur; //starting my chain from that point
        }
        else {
            struct Node *ptr = head;
            while(ptr -> next != NULL){
                ptr = ptr -> next;
            }
            ptr -> next = cur;
        }
    }
    linkedlistTraversal(head);
}