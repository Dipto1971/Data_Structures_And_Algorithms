#include<bits/stdc++.h>
using namespace std;

class RadixTreeNode {
public:
    std::unordered_map<char, RadixTreeNode*> children;
    bool isEndOfWord;

    RadixTreeNode() : isEndOfWord(false) {}

    ~RadixTreeNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

class RadixTree {
private:
    RadixTreeNode* root;

public:
    RadixTree() {
        root = new RadixTreeNode();
    }

    ~RadixTree() {
        delete root;
    }

    // Insert a string into the radix tree
    void insert(const std::string& key) {
        RadixTreeNode* node = root;

        for (char c : key) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new RadixTreeNode();
            }
            node = node->children[c];
        }

        node->isEndOfWord = true;
    }

    // Search for a string in the radix tree
    bool search(const std::string& key) {
        RadixTreeNode* node = root;

        for (char c : key) {
            if (node->children.find(c) == node->children.end()) {
                return false; // Character not found in the tree
            }
            node = node->children[c];
        }

        return node->isEndOfWord; // Return true if it's an end-of-word node
    }

    // Delete a string from the radix tree
    void remove(const std::string& key) {
        removeHelper(root, key, 0);
    }

private:
    // Recursive helper function for deletion
    bool removeHelper(RadixTreeNode* node, const std::string& key, int depth) {
        if (node == nullptr) {
            return false; // Key not found
        }

        if (depth == key.length()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false; // Mark as non-end-of-word
                return true; // Key found and marked as deleted
            }
            return false; // Key not found
        }

        char currentChar = key[depth];
        if (removeHelper(node->children[currentChar], key, depth + 1)) {
            // If child node is marked as deleted, check if it can be removed
            if (node->children[currentChar]->children.empty() && !node->children[currentChar]->isEndOfWord) {
                delete node->children[currentChar];
                node->children.erase(currentChar);
            }
            return true;
        }
        return false;
    }
};

int main() {
    RadixTree tree;
    std::string choice;

    while (true) {
        std::cout << "\nRadix Tree Menu:\n";
        std::cout << "1. Insert a string\n";
        std::cout << "2. Delete a string\n";
        std::cout << "3. Search for a string\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::string key;
            std::cout << "Enter a string to insert: ";
            std::cin >> key;
            tree.insert(key);
            std::cout << "'" << key << "' inserted into the tree.\n";
        } else if (choice == "2") {
            std::string key;
            std::cout << "Enter a string to delete: ";
            std::cin >> key;
            if (tree.search(key)) {
                tree.remove(key);
                std::cout << "'" << key << "' deleted from the tree.\n";
            } else {
                std::cout << "'" << key << "' not found in the tree.\n";
            }
        } else if (choice == "3") {
            std::string key;
            std::cout << "Enter a string to search: ";
            std::cin >> key;
            if (tree.search(key)) {
                std::cout << "'" << key << "' found in the tree.\n";
            } else {
                std::cout << "'" << key << "' not found in the tree.\n";
            }
        } else if (choice == "4") {
            break; // Exit the program
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}