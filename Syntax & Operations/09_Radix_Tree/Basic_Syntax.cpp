#include <iostream>
#include <unordered_map>
#include <string>

struct RadixTreeNode {
    std::unordered_map<char, RadixTreeNode*> children;
    bool isEndOfWord;
};

struct RadixTree {
    RadixTreeNode* root;

    RadixTree() {
        root = new RadixTreeNode();
    }
};

// Insert a string into the radix tree
void insert(RadixTree& tree, const std::string& key) {
    RadixTreeNode* node = tree.root;

    for (char c : key) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new RadixTreeNode();
        }
        node = node->children[c];
    }

    node->isEndOfWord = true;
}

// Search for a string in the radix tree
bool search(const RadixTree& tree, const std::string& key) {
    RadixTreeNode* node = tree.root;

    for (char c : key) {
        if (node->children.find(c) == node->children.end()) {
            return false; // Character not found in the tree
        }
        node = node->children[c];
    }

    return node->isEndOfWord; // Return true if it's an end-of-word node
}

int main() {
    RadixTree tree;

    // Insert some strings into the radix tree
    insert(tree, "apple");
    insert(tree, "app");
    insert(tree, "banana");
    insert(tree, "bat");

    // Search for strings
    std::cout << "Search 'apple': " << (search(tree, "apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'app': " << (search(tree, "app") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'banana': " << (search(tree, "banana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'batman': " << (search(tree, "batman") ? "Found" : "Not Found") << std::endl;

    return 0;
}
