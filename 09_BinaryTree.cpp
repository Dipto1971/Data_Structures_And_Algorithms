#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data){
    struct node* n; //Creating a node pointer
    n = (struct node*) malloc (sizeof(struct node));
    n-> data = data;
    n-> left = NULL;
    n-> right = NULL;

    return n; //returning the node
}
int main(){

    struct node *p = (struct node *) malloc (sizeof(struct node));
    p-> left = NULL;
    p-> right = NULL;

    struct node *p1 = (struct node *) malloc (sizeof(struct node));
    p1-> left = NULL;
    p1-> right = NULL;

    struct node *p2 = (struct node *) malloc (sizeof(struct node));
    p2-> left = NULL;
    p2-> right = NULL;
    
    p->left = p1;
    p->right = p2;
    //Above is the inefficient way to construct a tree

    struct node *eff_p = createnode(10); /*This will actually do the same thing*/

    return 0;
}