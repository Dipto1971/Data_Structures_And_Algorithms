#include<bits/stdc++.h>
using namespace std;

class RadixTreeNode {
public:
    unordered_map<char, RadixTreeNode*> children;
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
    void insert(const string& key) {
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
    bool search(const string& key) {
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
    void remove(const string& key) {
        removeHelper(root, key, 0);
    }

private:
    // Recursive helper function for deletion
    bool removeHelper(RadixTreeNode* node, const string& key, int depth) {
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

    // Insert some strings into the radix tree
    tree.insert("apple");
    tree.insert("app");
    tree.insert("banana");
    tree.insert("bat");

    // Search for strings
    cout << "Search 'apple': " << (tree.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (tree.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (tree.search("banana") ? "Found" : "Not Found") << endl;
    cout << "Search 'batman': " << (tree.search("batman") ? "Found" : "Not Found") << endl;

    // Delete a string and search again
    tree.remove("apple");
    cout << "Search 'apple' after deletion: " << (tree.search("apple") ? "Found" : "Not Found") << endl;

    return 0;
}
