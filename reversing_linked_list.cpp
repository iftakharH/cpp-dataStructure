#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* head = nullptr;

void insertAtLast(int val) {
    Node* ptr = new Node{val, nullptr};
    if (head == nullptr) {
        head = ptr;
    } else {
        Node* temp = head;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

void printList() {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

void reverseLinkedList() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    cout << "Reversing a linked list:" << endl;
    head = nullptr;
    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(4);
    printList();
    reverseLinkedList();
    printList();
}