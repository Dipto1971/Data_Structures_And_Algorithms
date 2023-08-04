/*Exercise 1:
Insert Operation
Whenever an element is to be inserted, first locate its proper location. Start searching from the
root node, then if the data is less than the key value, search for the empty location in the left
sub tree and insert the data. Otherwise, search for the empty location in the right sub tree and
insert the data.
Exercise 2:
Search Operation
Whenever an element is to be searched, start searching from the root node. Then if the data is
less than the key value, search for the element in the left subtree. Otherwise, search for the
element in the right subtree. Follow the same algorithm for each node.
Exercise 3:
Traversal Operation
Perform Pre, Post and In-order traversal of BST
Exercise 4:
Deletion Operation
Perform deletion operation of BST. You have to perform the following three operations:
1) Node to be deleted is leaf: Simply remove from the tree.
2) Node to be deleted has only one child: Copy the child to the node and delete the child
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of
the in-order successor to the node and delete the inorder successor. Note that inorder
predecessor can also be used.
Exercise 5:
Smallest and Largest Element Searching Operation
Find maximum and minimum element from BST*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->right = NULL;
        root->left = NULL;
        root->data = data;
        return root;
    }
    else if (data < root->data)
        root->left = insertNode(root->left, data);

    else
        root->right = insertNode(root->right, data);

    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
struct node *createnode(int data)
{
    struct node *n; // Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n; // returning the node
}

struct node* findMaxNode(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* findMinNode(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    do {
        cout << "Binary Search Tree Operations Menu:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Search for a node" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. In-order traversal" << endl;
        cout << "5. Pre-order traversal" << endl;
        cout << "6. Post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            root = insertNode(root, data);
            break;
        case 2:
            cout << "Enter the key to search: ";
            cin >> data;
            struct node* result = search(root, data);
            if (result == NULL) {
                cout << "Node not found!" << endl;
            } else {
                cout << "Node found: " << result->data << endl;
            }
            break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> data;
            root = deleteNode(root, data);
            break;
        case 4:
            cout << "In-order traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Pre-order traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Post-order traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 7:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}
