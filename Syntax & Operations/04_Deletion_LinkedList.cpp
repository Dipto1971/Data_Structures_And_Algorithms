#include<bits/stdc++.h>
using namespace std;
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

struct node *deleteAtFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct node *deleteAtPosition(struct node *head, int position)
{
    struct node *p = head;
    struct node *q = head->next;
    int i;
    for (i = 0; i < position - 1; i++)
    {
        p = p->next;
        q = q->next;
        if (q->next == NULL && i < position - 2)
        {
            cout << "Could not delete node!" << endl;
            return head;
        }
    }
        p->next = q->next;
        free(q);
        return head;
};

struct node *deleteAtlast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
};

