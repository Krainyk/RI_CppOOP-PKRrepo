#include <iostream>
#include "Header.h"

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

bool hasDuplicates(Node* head) {
    if (head == NULL) return false;

    for (Node* first = head; first != NULL; first = first->next) {

        for (Node* second = first->next; second != NULL; second = second->next) {
            if (first->info == second->info) {
                return true;
            }
        }
    }
    return false;
}