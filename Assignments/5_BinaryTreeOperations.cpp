/*
Exercise 1:
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
Find maximum and minimum element from BST
*/


#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void preorder (struct node* root){
    if(root!= NULL){
        cout << root -> data << endl;
        preorder(root-> left);
        preorder(root-> right);
    }
}

void postorder (struct node *root){
    if(root != NULL){
        postorder(root-> left);
        postorder(root-> right);
        cout << root-> data; 
    }
}

void inorder (struct node *root){
    if(root != NULL){
        inorder(root-> left);
        cout << root-> data; 
        inorder(root-> right);
    }
}
struct node* createnode(int data){
    struct node* n; //Creating a node pointer
    n = (struct node*) malloc (sizeof(struct node));
    n-> data = data;
    n-> left = NULL;
    n-> right = NULL;

    return n; //returning the node
}
int main(){

}