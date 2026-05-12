#pragma once
#include "Product.h"
#include <vector>
#include <string>

TrieNode* createTrie();
bool insertTrie(TrieNode* root, const Product& p);
Product* searchTrie(TrieNode* root, const std::string& name);
bool removeTrie(TrieNode* root, const std::string& name);

void getProductsByStoreTrie(TrieNode* node, const std::string& store, std::vector<Product>& result);
void getProductsByPriceTrie(TrieNode* node, double minP, double maxP, std::vector<Product>& result);