/*
*/

#include <iostream>
using namespace std;

struct ListNode {
    int value;
    struct ListNode* next;
    ListNode(int value) {
        this->value = value;
        next = NULL;
    }
};

struct LinkedList {
    ListNode* head;
    LinkedList() { head = NULL; }

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    void print() {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void insert(int value) {
        ListNode* temp = new ListNode(value);
        temp->next = head;
        head = temp;
    }
};


int main() {
    LinkedList ll;

    cout << "Input data (use 'e' to exit):" << endl;
    int value;
    while (cin >> value && value != 'e')
        ll.insert(value);

    cout << "Given linked list:" << endl;
    ll.print();

    ll.head = ll.reverse(ll.head);

    cout << "\nReversed linked list:" << endl;
    ll.print();
    return 0;
}
