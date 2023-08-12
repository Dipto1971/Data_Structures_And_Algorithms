#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
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

// Function to count leaf nodes in a binary tree
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) //it is a leaf node
        return 1;
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Construct a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Count and print the number of leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    // Clean up: Free allocated memory
    // Note: In a complete program, you should also free the memory for the entire tree.

    return 0;
}
