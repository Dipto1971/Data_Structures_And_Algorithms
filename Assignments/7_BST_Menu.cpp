#include <bits/stdc++.h>
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
        cout << root->data << " ";
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
        cout << root->data << " ";
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
        cout << root->data << " ";
        inorder(root->right);
    }
}

struct node *findMaxNode(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *findMinNode(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete root;
            return temp;
        }

        struct node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void deleteTree(struct node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    do
    {
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

        switch (choice)
        {
        case 1:
        {
            cout << "Enter data to insert: ";
            cin >> data;
            root = insertNode(root, data);
            break;
        }
        case 2:
            {
                cout << "Enter the key to search: ";
            cin >> data;
            struct node *result = search(root, data);
            if (result == NULL)
            {
                cout << "Node not found!" << endl;
            }
            else
            {
                cout << "Node found: " << result->data << endl;
            }
            break;
            }
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
            deleteTree(root); // Deallocate memory for the entire tree before exiting.
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}
