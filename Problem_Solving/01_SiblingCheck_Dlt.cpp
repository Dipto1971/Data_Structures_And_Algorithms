/**/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root= NULL;

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
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

void findSiblings(struct node *root){
    if(root-> left== NULL && root->right== NULL){
        return;
    }
    if(root->left!= NULL && root->right!= NULL){
        cout << root->left->data << " and " << root->right->data << endl;
        findSiblings(root->left);
        findSiblings(root->right);
    }
    else if(root->left!= NULL && root->right== NULL){
        root-> left= NULL;
        free(root-> left);
    }
    else if(root->right!= NULL && root->left== NULL){
        root-> right= NULL;
        free(root-> right);
    }
}
int main()
{
    cout << "Enter total elements of the tree" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insertNode(root, data);
        cout << "Element added: " << data << endl;
    }
    cout << "PerOrderTraversal: " << endl;
    preorder(root);
    cout << endl << "Following pairs are siblings: " << endl;
    findSiblings(root);
    cout << "After deletion: " << endl;
    preorder(root);
}