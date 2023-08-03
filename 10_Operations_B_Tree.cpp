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