
/*
A linked list is a sequence of data structures, which are connected together via links. Linked List
is a sequence of links which contains items. Each link contains a connection to another link.
Linked list is the second most-used data structure after array.
Linked list can be visualized as a chain of nodes, where every node points to the next node.

-> Create a menu that will display all the options(Create Linked List, Insert New Node at beginning,
Insert New Node at any position,Delete Node from last position, Delete Node from beginning,
Delete Node from any position, Reverse Linked list, Remove Duplicate data from Linked list) as a list
and prompt user to select any desired option. The menu can be designed in below format.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void removeDuplicates(node* start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If matches then delete it */
            if (ptr1->data == ptr2->next->data) {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void reverse (struct node** head){
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while(current != NULL){
        // Store next
        next = current -> next;
        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}

void linkedlistTraversal(struct node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        cout << "Position " << i << " data: " << ptr->data << endl;
        cout << "Next address: " << ptr->next << endl;
        ptr = ptr->next;
        i++;
    }
}

struct node *insertAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
};

struct node *insertAtIndex(struct node *head, int position, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 1;
    while (i != position - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
};

struct node *insertAtEnd(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
};

struct node *insertAfterNode(struct node *head, struct node *previous_node, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = previous_node->next;
    previous_node->next = ptr;

    return head;
};

// Deletion

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

struct node *head = NULL;
int main()
{
    while (true)
    {

        if (head == NULL)
        {
            cout << "LinkedList is empty, Enter value at head! " << endl;

            cout << "Enter data: ";
            int data;
            cin >> data;
            head = insertAtBeg(head, data);

            linkedlistTraversal(head);
        }
        else
        {
            cout << "\t\t"
                 << "Linked List Menu"
                 << "\t\t" << endl;
            cout << "Enter 1 to Insert at the beginning " << endl;
            cout << "Enter 2 to Insert at desired position " << endl;
            cout << "Enter 3 to Insert at the END " << endl;
            cout << "Enter 4 to Insert a New Node " << endl;
            cout << "Enter 5 Delete the first Node " << endl;
            cout << "Enter 6 to Delete at any Position " << endl;
            cout << "Enter 7 to Delete the last Element " << endl;
            cout << "Enter 8 to Reverse the linked list " << endl;
            cout << "Enter 9 to Remove all the duplicate data" << endl;

            cout << "1 to 9? \n -> ";
            int choice;
            cin >> choice;

            switch (choice)
            {

            case 1:
            {
                cout << "Enter the Value you want to enter: ";
                int d1;
                cin >> d1;
                head = insertAtBeg(head, d1);

                linkedlistTraversal(head);
                break;
            }

            case 2:
            {
                cout << "Enter the data of Node: " << endl;
                int d2;
                cin >> d2;
                cout << "Enter the position: " << endl;
                int pos;
                cin >> pos;
                head = insertAtIndex(head, pos, d2);
                linkedlistTraversal(head);
                break;
            }

            case 3:
            {
                cout << "Enter the value: ";
                int d3;
                cin >> d3;
                insertAtEnd(head, d3);
                linkedlistTraversal(head);
                break;
            }

            case 4:
            {
                cout << "Enter the data of Node: " << endl;
                int d4;
                cin >> d4;
                struct node *prev = head;

                while (prev->next != NULL)
                {
                    prev = prev->next;
                }
                head = insertAfterNode(head, prev, d4);
                linkedlistTraversal(head);

                free(prev);
                break;
            }

            case 5:
            {
                head = deleteAtFirst(head);
                linkedlistTraversal(head);
                break;
            }

            case 6:
            {
                cout << "Enter the position of deletion: ";
                int pos;
                cin >> pos;

                head = deleteAtPosition(head, pos);
                linkedlistTraversal(head);
                break;
            }

            case 7:
            {
                head = deleteAtlast(head);
                linkedlistTraversal(head);
                break;
            }

            case 8:
            {
                reverse(&head);
                linkedlistTraversal(head);
                break;
            }
            
            case 9:
            {
                removeDuplicates(head);
                linkedlistTraversal(head);
                break;
            }
            }
        }
    }
}
