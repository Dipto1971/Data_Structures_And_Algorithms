#include<bits/stdc++.h>



struct node{
    int data;
    struct node *next; //Struct Node type pointer which will point types like it
};

void linkedlistTraversal(struct node *ptr){ //Time Complexity: O(n)
    while(ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    
    //Allocate memory for nodes in the linked list in Heap > Dynamic Memory Allocation
    head= (struct node*) malloc(sizeof (struct node)); 
    second= (struct node*) malloc(sizeof (struct node));
    third= (struct node*) malloc(sizeof (struct node));

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

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p= head;
    struct node *q= head-> next;

    for(int i=0; i< index-1; i++){
        p = p-> next; //deleted element's prevoius element
        q = q-> next; //q will be the node to be deleted after loop execution
    }
    p-> next = q-> next; //deleted item's next address is now transferred to previous item's next address
    free(q);

    return head;
};

