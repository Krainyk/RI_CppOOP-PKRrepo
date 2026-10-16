#pragma once
struct Node {
    int info;
    Node* next;
};

void addNode(Node*& head, int value);
bool searchValue(Node* current, int target);
bool hasDuplicates(Node* head);