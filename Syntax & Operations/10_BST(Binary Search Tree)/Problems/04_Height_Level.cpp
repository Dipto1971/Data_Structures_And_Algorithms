#include <stdio.h>
#include <stdlib.h>


/*Determination of a node's height and level*/

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

struct TreeNode* findNode(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

int getNodeHeight(struct TreeNode* node) {
    if (node == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = getNodeHeight(node->left);
    int rightHeight = getNodeHeight(node->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int getNodeLevel(struct TreeNode* root, int data, int level) {
    if (root == NULL) {
        return -1; // Node not found
    }

    if (data == root->data) {
        return level;
    } else if (data < root->data) {
        return getNodeLevel(root->left, data, level + 1);
    } else {
        return getNodeLevel(root->right, data, level + 1);
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

    struct TreeNode* node = findNode(root, targetNode);

    if (node != NULL) {
        int nodeHeight = getNodeHeight(node);
        int nodeLevel = getNodeLevel(root, targetNode, 0);

        printf("Node %d is at level %d and its height is %d\n", targetNode, nodeLevel, nodeHeight);
    } else {
        printf("Node %d not found in the tree.\n", targetNode);
    }

    return 0;
}
