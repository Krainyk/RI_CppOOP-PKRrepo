#include "List.h"
#include <iostream>

using namespace std;

Node* appendNode(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        return newNode;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

void printList(Node* head) {
    if (!head) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Список: ";
    Node* current = head;
    while (current != nullptr) {
        cout << "[" << current->data << "]";
        if (current->next) cout << " <-> ";
        current = current->next;
    }
    cout << "\n";
}

void destroyList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

Node* deletePrecedingNodes(Node* head, int targetValue) {
    if (!head) return nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data == targetValue && current->prev != nullptr) {

            Node* toDelete = current->prev;

            if (toDelete->prev != nullptr) {
                toDelete->prev->next = current;
            }
            else {
                head = current;
            }

            current->prev = toDelete->prev;

            delete toDelete;
        }

        current = current->next;
    }

    return head;
}