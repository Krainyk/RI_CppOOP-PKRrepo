#pragma once
#include <string>
#include <unordered_map>

struct Product {
    std::string name;
    std::string store;
    double price;
    double quantity;
    std::string unit;
};

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    Product data;

    TrieNode() : isEndOfWord(false) {}
};