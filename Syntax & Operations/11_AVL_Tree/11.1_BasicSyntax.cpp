#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
    int height;
};

int getHeight (struct node *n){
    if(n == NULL) return 0;
    return n-> height;
}

struct node *createNode(int key){
    struct node *node = (struct node *) malloc(sizeof(struct node));

    node-> key = key;
    node-> left = NULL;
    node-> right = NULL;
    node-> height = 1;
}

int getBalancedfactor(struct node *n){
    if (n == NULL) return 0;
    return getHeight(n-> left) - getHeight(n-> right);
}

struct node *rightRotate (struct node *y){
    struct node * x = y-> left;
    struct node *T2 = x-> right;

    x-> right = y;
    y->left= T2;

    //Now we need to update the heights!
    y-> height = max (getHeight(y->right), getHeight(y->left)) + 1;
    x-> height = max (getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node *leftRotate (struct node *x){
    struct node *y = x-> right;
    struct node *T2 = y->left;

    y-> left = x;
    x-> right = T2;

    //Now update the height!
    y-> height = max (getHeight(y->right), getHeight(y->left)) + 1;
    x-> height = max (getHeight(x->right), getHeight(x->left)) + 1;

    return y;    
}

struct node *insertInBST(struct node *root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->left = insertInBST(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertInBST(root->right, key);
    }
    else {
        // Duplicate keys are not allowed in a BST
        return root;
    }
    
    // Update height and balance factor after insertion
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalancedfactor(root);

    // Balancing cases
    if (bf > 1 && key < root->left->key) {
        //bf>1 means height of left subtree is bigger
        //key < root->left->key means key is at left side of the root
        //so both cases are supporting left sides, so it is LL!
        return rightRotate(root);
    }

    if (bf < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printAVL(struct node *root, int level) {
    if (root == NULL) return;

    // Print right subtree first (higher levels)
    printAVL(root->right, level + 1);

    // Print current node
    for (int i = 0; i < level; i++) {
        cout << "   "; // Indent to visualize the level
    }
    cout << root->key << " (h=" << root->height << ", bf=" << getBalancedfactor(root) << ")" << endl;

    // Print left subtree (lower levels)
    printAVL(root->left, level + 1);
}

int main() {
    struct node *root = NULL;

    // Insert nodes to test AVL balancing
    root = insertInBST(root, 30);
    root = insertInBST(root, 20);
    root = insertInBST(root, 40);
    root = insertInBST(root, 10);
    root = insertInBST(root, 25);
    root = insertInBST(root, 35);
    root = insertInBST(root, 50);

    // Print the final AVL tree structure
    cout << "Final AVL Tree Structure:" << endl;
    printAVL(root, 0);

    return 0;
}
