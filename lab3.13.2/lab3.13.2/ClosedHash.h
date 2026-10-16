#pragma once
#include "Product.h"
#include <vector>
#include <string>

enum Status { EMPTY, ACTIVE, DELETED };

struct HashEntry {
    Product data;
    Status status;

    HashEntry() : status(EMPTY) {}
};

const int TABLE_SIZE = 101;
using ClosedHashTable = std::vector<HashEntry>;

ClosedHashTable createClosedTable();
int hashFunctionClosed(const std::string& key);

bool insertClosedHash(ClosedHashTable& table, const Product& p);
Product* searchClosedHash(ClosedHashTable& table, const std::string& name);
bool removeClosedHash(ClosedHashTable& table, const std::string& name);

std::vector<Product> getProductsByStoreClosed(const ClosedHashTable& table, const std::string& store);
std::vector<Product> getProductsByPriceClosed(const ClosedHashTable& table, double minP, double maxP);