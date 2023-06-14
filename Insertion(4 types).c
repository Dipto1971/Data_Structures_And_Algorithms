#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *insertAtFirst(struct node *head, int data){ // passing head node & data
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr-> next = head; //ptr will be new head, so it's next element address will be connected with head's address
    ptr -> data = data;

    return ptr; //ptr is the new head now
}

struct node *insertAtIndex(struct  node *head, int data, int index){
    // index is the address of which we want
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    //problem is we don't know where the index is, so we will run a while loop to reach there

    struct node *p = head; //reserving head Node

    int i=0;
    while(i!= index-1){
        p= p-> next;
        i++;
    }
    ptr-> data = data;
    ptr-> next = p-> next;
    p->next = ptr;

    /* p-next value transeferred to ptr-next &
    p-next got the address of ptr*/
    return head;
}

struct node *insertAtEnd(struct node *head, int data){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node *p = head;

    while(p -> next != NULL){
        p = p-> next;
    }
    p->next = ptr;
    ptr -> next = NULL;

    return head;
}

struct node *insertAfterNode(struct node *prevNode, int data){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    ptr-> data = data;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    return head;
}


