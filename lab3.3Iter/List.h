#pragma once

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* appendNode(Node* head, int val);
void printList(Node* head);
void destroyList(Node* head);

Node* deletePrecedingNodes(Node* head, int targetValue);