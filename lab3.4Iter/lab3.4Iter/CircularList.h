#pragma once

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* appendNode(Node* head, int val);
void printList(Node* head);
void destroyList(Node* head);

int countOddElements(Node* head);