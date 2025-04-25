#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* head = nullptr;

void printList() {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

void insertInSortedList(int val) {
    Node* newNode = new Node{val, nullptr};

    if (head == nullptr || val < head->info) {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->link != nullptr && current->link->info < val) {
        current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
}

int main() {
    insertInSortedList(3);
    cout << "List after inserting 3: ";
    printList();

    insertInSortedList(1);
    cout << "List after inserting 1: ";
    printList(); 

    insertInSortedList(5);
    cout << "List after inserting 5: ";
    printList(); 

    insertInSortedList(2);
    cout << "List after inserting 2: ";
    printList(); 

    insertInSortedList(0);
    cout << "List after inserting 0: ";
    printList(); 

    insertInSortedList(6);
    cout << "List after inserting 6: ";
    printList();

    return 0;
}