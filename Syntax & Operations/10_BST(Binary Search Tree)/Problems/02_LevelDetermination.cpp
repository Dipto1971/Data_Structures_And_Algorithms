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

int findLevel(struct TreeNode* root, int data, int level) {
    if (root == NULL) {
        return -1; // Node not found
    }

    if (data == root->data) {
        return level; // Node found, return the level
    } else if (data < root->data) {
        return findLevel(root->left, data, level + 1);
    } else {
        return findLevel(root->right, data, level + 1);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int data[] = {30, 20, 50, 10, 25, 35, 60};
    int dataSize = sizeof(data) / sizeof(data[0]);

    // Insert nodes into the BST
    for (int i = 0; i < dataSize; i++) {
        root = insert(root, data[i]);
    }

    int targetNode = 25;
    int level = findLevel(root, targetNode, 0);

    if (level != -1) {
        printf("Node %d is at level %d\n", targetNode, level);
    } else {
        printf("Node %d not found in the tree.\n", targetNode);
    }

    return 0;
}
