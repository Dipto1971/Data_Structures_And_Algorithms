
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void inorder (struct node *root){
    if(root != NULL){
        inorder(root-> left);
        cout << root-> data; 
        inorder(root-> right);
    }
}

int isBST (struct node *root){
    static struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root-> data <= prev-> data){
            return 0;
        }
        prev = root;
        return isBST(root-> right);
    }
    else{
        return 1;
    }
}

int main(){
}