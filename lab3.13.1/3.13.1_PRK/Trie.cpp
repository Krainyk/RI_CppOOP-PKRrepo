#include "Trie.h"

using namespace std;

TrieNode* createTrie() {
    return new TrieNode();
}

bool insertTrie(TrieNode* root, const Product& p) {
    TrieNode* current = root;
    for (char ch : p.name) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    if (current->isEndOfWord) return false;

    current->isEndOfWord = true;
    current->data = p;
    return true;
}

Product* searchTrie(TrieNode* root, const string& name) {
    TrieNode* current = root;
    for (char ch : name) {
        if (current->children.find(ch) == current->children.end()) {
            return nullptr;
        }
        current = current->children[ch];
    }
    if (current != nullptr && current->isEndOfWord) {
        return &(current->data);
    }
    return nullptr;
}

bool removeTrie(TrieNode* root, const string& name) {
    TrieNode* current = root;
    for (char ch : name) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    if (current->isEndOfWord) {
        current->isEndOfWord = false;
        return true;
    }
    return false;
}

void getProductsByStoreTrie(TrieNode* node, const string& store, vector<Product>& result) {
    if (!node) return;
    if (node->isEndOfWord && node->data.store == store) {
        result.push_back(node->data);
    }
    for (auto const& pair : node->children) {
        getProductsByStoreTrie(pair.second, store, result);
    }
}

void getProductsByPriceTrie(TrieNode* node, double minP, double maxP, vector<Product>& result) {
    if (!node) return;
    if (node->isEndOfWord && node->data.price >= minP && node->data.price <= maxP) {
        result.push_back(node->data);
    }
    for (auto const& pair : node->children) {
        getProductsByPriceTrie(pair.second, minP, maxP, result);
    }
}