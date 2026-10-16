#include "ClosedHash.h"

using namespace std;

ClosedHashTable createClosedTable() {
    return ClosedHashTable(TABLE_SIZE);
}

int hashFunctionClosed(const string& key) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

bool insertClosedHash(ClosedHashTable& table, const Product& p) {
    int index = hashFunctionClosed(p.name);
    int startIndex = index;

    do {
        if (table[index].status == EMPTY || table[index].status == DELETED) {
            table[index].data = p;
            table[index].status = ACTIVE;
            return true;
        }
        if (table[index].status == ACTIVE && table[index].data.name == p.name) {
            return false;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    return false;
}

Product* searchClosedHash(ClosedHashTable& table, const string& name) {
    int index = hashFunctionClosed(name);
    int startIndex = index;

    do {
        if (table[index].status == EMPTY) {
            return nullptr;
        }
        if (table[index].status == ACTIVE && table[index].data.name == name) {
            return &(table[index].data);
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    return nullptr;
}

bool removeClosedHash(ClosedHashTable& table, const string& name) {
    int index = hashFunctionClosed(name);
    int startIndex = index;

    do {
        if (table[index].status == EMPTY) {
            return false;
        }
        if (table[index].status == ACTIVE && table[index].data.name == name) {
            table[index].status = DELETED;
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    return false;
}


vector<Product> getProductsByStoreClosed(const ClosedHashTable& table, const string& store) {
    vector<Product> result;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i].status == ACTIVE && table[i].data.store == store) {
            result.push_back(table[i].data);
        }
    }
    return result;
}

vector<Product> getProductsByPriceClosed(const ClosedHashTable& table, double minP, double maxP) {
    vector<Product> result;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i].status == ACTIVE && table[i].data.price >= minP && table[i].data.price <= maxP) {
            result.push_back(table[i].data);
        }
    }
    return result;
}