#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int data[] = {30, 20, 50, 10, 25, 35, 60};
    int dataSize = sizeof(data) / sizeof(data[0]);

    // Insert nodes into the BST
    for (int i = 0; i < dataSize; i++) {
        root = insert(root, data[i]);
    }

    int nodeCount = countNodes(root);

    printf("Number of nodes in the BST: %d\n", nodeCount);

    return 0;
}
