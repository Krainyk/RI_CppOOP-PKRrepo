#pragma once
struct Node {
    int info;
    Node* next;
};

void addNode(Node*& head, int value);
bool hasDuplicates(Node* head);