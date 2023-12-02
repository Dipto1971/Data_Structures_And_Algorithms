#include <stdio.h>
// structure for creating nodes
struct node
{
    int data;
    struct node *next;
};
struct node *insertAtFirst(struct node *head, int data)
{ // insertion at begining
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}
struct node *insert(struct node *head, int data, int index)
{ // insertion at any point
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    struct node *ptr = head;
    newnode->data = data;
    if (index == 0)
    {
        newnode->next = head;
        return newnode;
    }
    for (int i = 0; i < index - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("invalid");
        return head;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
};
int main()
{
    struct node *head = NULL, *tail = NULL;
    int data, i, numofnodes, n, index;
    printf("how many nodes u want to create:");
    scanf("%d", &numofnodes);
    for (i = 0; i < numofnodes; i++)
    {
        printf("enter data for node %d=", i + 1);
        scanf("%d", &n);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->next = NULL; // Initialize new node's next pointer
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    printf("\nBefore insertion linkedlist:");
    linkedlisttraversal(head);
    printf("\nIf u want u can do this:");
    printf("\n1.Insert new node\n2. Insert node at beginning\n3. Insert node at any position\n4.Delete Node from last position\n5.Delete Node from beginning\n6.Delete Node from any position\n7.Remove Duplicate data from Linked list");
    printf(" \n\nwhat changes u want:");
    scanf("%d", &n);
    if (n < 3)
    {
        printf("\nhow much u want to add=");
        scanf("%d", &n);
        head = insertAtFirst(head, n);
    }
    else if (n == 3)
    {
        printf("\nenter the position u want to add:");
        scanf("%d", &index);
        printf("\nenter the data u want to add:");
        scanf("%d", &n);
        head = insert(head, n, index);
    }
    printf("\nAfter insertion linkedlist:");
    linkedlisttraversal(head);
}
// Function to traverse and print the linked listn
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
