#include<stdio.h>
#include<stdlib.h> // for using malloc

struct Node{
    int data;
    struct Node *next; //Struct Node type pointer which will point types like it
};

void linkedlistTraversal(struct Node *ptr){ //Time Complexity: O(n)
    while(ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    
    //Allocate memory for nodes in the linked list in Heap > Dynamic Memory Allocation
    head= (struct Node*) malloc(sizeof (struct Node)); 
    second= (struct Node*) malloc(sizeof (struct Node));
    third= (struct Node*) malloc(sizeof (struct Node));

    //Once we do this kind of dynamic memory allocation, we can link Nodes
    
    //Link first and second Nodes and so on..
    head -> data = 7;
    head -> next = second;

    second -> data = 77;
    second -> next = third;

    third -> data = 78;
    third -> next = NULL; //terminating the third Node

    linkedlistTraversal(head);

    return 0;
}
