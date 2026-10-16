#include "CircularList.h"
#include <iostream>

using namespace std;

Node* appendNode(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
    return head;
}

void printList(Node* head) {
    if (!head) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Список: ";
    Node* current = head;
    do {
        cout << "[" << current->data << "] -> ";
        current = current->next;
    } while (current != head);

    cout << "(замикається на " << head->data << ")\n";
}

void destroyList(Node* head) {
    if (!head) return;

    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

int countOddElements(Node* head) {
    if (!head) return 0;

    int count = 0;
    Node* current = head;

    do {
        if (current->data % 2 != 0) {
            count++;
        }
        current = current->next;
    } while (current != head);

    return count;
}