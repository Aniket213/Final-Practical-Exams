#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;

        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }

            current = current->children[c];
        }

        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;

        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }

            current = current->children[c];
        }

        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apricot");
    trie.insert("ape");
    trie.insert("bat");
    trie.insert("bee");
    trie.insert("best");
    trie.insert("blue");

    std::cout << "Searching for 'ape': " << (trie.search("ape") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'banana': " << (trie.search("banana") ? "Found" : "Not found") << std::endl;

    return 0;
}
