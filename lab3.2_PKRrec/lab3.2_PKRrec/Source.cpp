#include "Header.h"
#include <iostream>

void addNode(Node*& head, int value) {
    Node* newNode = new Node{ value, NULL };
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

bool searchValue(Node* current, int target) {
    if (current == NULL) return false;
    if (current->info == target) return true;

    return searchValue(current->next, target);
}

bool hasDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    if (searchValue(head->next, head->info)) {
        return true;
    }

    return hasDuplicates(head->next);
}