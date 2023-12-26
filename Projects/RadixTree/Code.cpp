#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct RadixTreeNode {
    struct RadixTreeNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

typedef struct RadixTreeNode RadixTreeNode;

struct RadixTree {
    RadixTreeNode* root;
};

typedef struct RadixTree RadixTree;

RadixTreeNode* createRadixNode() {
    RadixTreeNode* node = (RadixTreeNode*)malloc(sizeof(RadixTreeNode));
    if (node != NULL) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            node->children[i] = NULL;
        }
    }
    return node;
}

RadixTree* createRadixTree() {
    RadixTree* tree = (RadixTree*)malloc(sizeof(RadixTree));
    if (tree != NULL) {
        tree->root = createRadixNode();
    }
    return tree;
}

void insert(RadixTree* tree, const char* key) {
    RadixTreeNode* node = tree->root;
    while (*key) {
        int index = *key - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createRadixNode();
        }
        node = node->children[index];
        ++key;
    }
    node->isEndOfWord = true;
}

bool search(RadixTree* tree, const char* key) {
    RadixTreeNode* node = tree->root;
    while (*key) {
        int index = *key - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
        ++key;
    }
    return node->isEndOfWord;
}

bool removeHelper(RadixTreeNode* node, const char* key, int depth) {
    if (node == NULL) {
        return false;
    }
    if (depth == strlen(key)) {
        if (node->isEndOfWord) {
            node->isEndOfWord = false;
            return true;
        }
        return false;
    }
    int currentChar = key[depth] - 'a';
    if (removeHelper(node->children[currentChar], key, depth + 1)) {
        if (node->children[currentChar] != NULL && node->children[currentChar]->isEndOfWord == false) {
            free(node->children[currentChar]);
            node->children[currentChar] = NULL;
        }
        return true;
    }
    return false;
}

void removeKey(RadixTree* tree, const char* key) {
    removeHelper(tree->root, key, 0);
}

void printTreeHelper(RadixTreeNode* node, char* prefix, int level) {
    if (node->isEndOfWord) {
        prefix[level] = '\0';
        printf("%s\n", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i] != NULL) {
            prefix[level] = 'a' + i;
            printTreeHelper(node->children[i], prefix, level + 1);
        }
    }
}

void printTree(RadixTree* tree) {
    printf("Radix Tree Contents:\n");
    char prefix[100];
    printTreeHelper(tree->root, prefix, 0);
}

int main() {
    RadixTree* tree = createRadixTree();
    char choice[2];
    while (1) {
        printf("\nRadix Tree Menu:\n");
        printf("1. Insert a string\n");
        printf("2. Delete a string\n");
        printf("3. Search for a string\n");
        printf("4. Print the radix tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            char key[100];
            printf("Enter a string to insert: ");
            scanf("%s", key);
            insert(tree, key);
            printf("'%s' inserted into the tree.\n", key);
        } else if (strcmp(choice, "2") == 0) {
            char key[100];
            printf("Enter a string to delete: ");
            scanf("%s", key);
            if (search(tree, key)) {
                removeKey(tree, key);
                printf("'%s' deleted from the tree.\n", key);
            } else {
                printf("'%s' not found in the tree.\n", key);
            }
        } else if (strcmp(choice, "3") == 0) {
            char key[100];
            printf("Enter a string to search: ");
            scanf("%s", key);
            if (search(tree, key)) {
                printf("'%s' found in the tree.\n", key);
            } else {
                printf("'%s' not found in the tree.\n", key);
            }
        } else if (strcmp(choice, "4") == 0) {
            printTree(tree);
        } else if (strcmp(choice, "5") == 0) {
            printf("Operations are complete.\nExiting from the system.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(tree->root);
    free(tree);

    return 0;
}