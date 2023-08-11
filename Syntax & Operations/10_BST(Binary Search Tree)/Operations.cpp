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
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    int key = 30;
    struct node *searchResult = search(root, key);
    if (searchResult != NULL)
        cout << "Key " << key << " found in the tree." << endl;
    else
        cout << "Key " << key << " not found in the tree." << endl;

    struct node *maxNode = findMaxNode(root);
    cout << "Maximum value in the tree: " << maxNode->data << endl;

    struct node *minNode = findMinNode(root);
    cout << "Minimum value in the tree: " << minNode->data << endl;

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);
    cout << "Inorder traversal after deleting " << keyToDelete << ":" << endl;
    inorder(root);
    cout << endl;

    return 0;
}
