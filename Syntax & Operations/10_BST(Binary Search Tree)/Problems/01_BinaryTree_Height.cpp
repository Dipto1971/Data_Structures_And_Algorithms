#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of a binary tree
int getHeight(struct TreeNode* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // The height of the tree is the maximum of left and right subtree heights
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    // Example binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int height = getHeight(root);
    printf("Height of the binary tree: %d\n", height);

    return 0;
}
