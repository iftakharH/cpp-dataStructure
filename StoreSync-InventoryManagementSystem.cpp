//This program is a simple inventory and sales management system. It allows users to add, delete, buy, and edit products in the inventory. The program uses a linked list to store product information and provides a user-friendly interface for managing the inventory. The receipt is printed at the end of the purchase process, showing the items bought and the total amount due.
// The program is designed to be easy to use and provides clear instructions for the user. It also handles invalid inputs gracefully, ensuring a smooth user experience. The program is written in C++ and uses standard libraries for input/output operations.
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

struct Node {
    int ID;
    string proName;
    double prePrice;
    int quantity;
    Node* next;
};
Node* head = nullptr;

void addProduct();
void deleteProduct();
void buyProducts();
int searchProduct(int id);
int displayProducts();
string formatQuantity(int quantity);
void clearInputBuffer();
void editProduct();
void printReceipt(const vector<pair<string, double>>& items, double total);

int main() {
    system("color f0");
    cout << "\n\t\t\t\t ** StoreSync: Inventory & Sales Management System ** \n\n";

    while (true) {
        cout << "\t\t\t\t\t1. Add a new product\n";
        cout << "\t\t\t\t\t2. Delete a product\n";
        cout << "\t\t\t\t\t3. Buy products\n";
        cout << "\t\t\t\t\t4. Edit product\n";
        cout << "\t\t\t\t\t0. Exit\n";
        cout << "\t\t\t\t\t--------------------\n";
        cout << "\t\t\t\tEnter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            clearInputBuffer();
            cout << "\t\t\t\t\tInvalid input. Please enter a number.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                buyProducts();
                break;
            case 4:
                editProduct();
                break;
            case 0:
                cout << "\t\t\t\t\tExiting... Goodbye!\n";
                return 0;
            default:
                cout << "\t\t\t\t\tInvalid choice. Please try again.\n\n";
        }
    }
}

void addProduct() {
    system("cls");
    Node* newNode = new Node;

    cout << "\t\t\t\t\tEnter product ID: ";
    cin >> newNode->ID;

    cout << "\t\t\t\t\tEnter product name: ";
    cin.ignore();
    getline(cin, newNode->proName);

    cout << "\t\t\t\t\tEnter product price: ";
    cin >> newNode->prePrice;

    cout << "\t\t\t\t\tEnter product quantity: ";
    cin >> newNode->quantity;

    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    system("cls");
    cout << "\t\t\t\t\tProduct added successfully!\n\n";
}

void deleteProduct() {
    system("cls");
    if (head == nullptr) {
        cout << "\t\t\t\t\tList is empty.\n\n";
        return;
    }

    displayProducts();

    cout << "\t\t\t\t\tEnter product ID to delete: ";
    int id;
    cin >> id;

    int position = searchProduct(id);
    int count = displayProducts();

    if (position <= count) {
        Node* current = head;
        Node* previous = nullptr;

        if (current->ID == id) {
            head = current->next;
            delete current;
        } else {
            while (current->ID != id) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
        }
        system("cls");
        cout << "\t\t\t\t\tProduct deleted successfully!\n\n";
    } else {
        cout << "\t\t\t\t\tProduct not found.\n\n";
    }
}

void buyProducts() {
    system("cls");
    if (head == nullptr) {
        cout << "\t\t\t\t\tNo products available.\n\n";
        return;
    }

    int numItems;
    cout << "\t\t\t\t\tHow many items do you want to buy? ";
    cin >> numItems;

    if (numItems <= 0) {
        cout << "\t\t\t\t\tInvalid number of items.\n\n";
        return;
    }

    vector<pair<string, double>> boughtItems;
    double totalPrice = 0;

    for (int i = 0; i < numItems; ++i) {
        displayProducts();

        cout << "\t\t\t\t\tEnter ID of item " << (i + 1) << ": ";
        int id;
        cin >> id;

        Node* current = head;
        int position = searchProduct(id);
        int count = displayProducts();

        if (position <= count) {
            while (current->ID != id) {
                current = current->next;
            }

            int quantity;
            cout << "\t\t\t\t\tEnter quantity: ";
            cin >> quantity;

            if (current->quantity >= quantity) {
                boughtItems.push_back({current->proName, current->prePrice * quantity});
                totalPrice += current->prePrice * quantity;
                current->quantity -= quantity;
            } else {
                cout << "\t\t\t\t\tInsufficient quantity.\n\n";
                i--;
            }
        } else {
            cout << "\t\t\t\t\tItem not found.\n\n";
            i--;
        }
    }

    system("cls");
    printReceipt(boughtItems, totalPrice);
    cout << "\n\t\t\t\t\tThank you for shopping!\n\n";
}

int searchProduct(int id) {
    int count = 1;
    Node* current = head;
    while (current != nullptr) {
        if (current->ID == id) {
            break;
        }
        count++;
        current = current->next;
    }
    return count;
}

int displayProducts() {
    system("cls");
    int count = 0;
    Node* current = head;

    cout << "\t\t\t\t\tExisting products:\n";
    cout << "\t\t\t\t\t" << left << setw(5) << "ID" << setw(20) << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    cout << "\t\t\t\t\t---------------------------------------------\n";
    while (current != nullptr) {
        cout << "\t\t\t\t\t" << left << setw(5) << current->ID << setw(20) << current->proName << setw(10) << current->prePrice << setw(10) << formatQuantity(current->quantity) << endl;
        current = current->next;
        count++;
    }
    cout << "\n\t\t\t\t\tTotal products: " << count << "\n\n";
    return count;
}

string formatQuantity(int quantity) {
    if (quantity <= 0) {
        return "Out of stock";
    } else {
        return to_string(quantity);
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void editProduct() {
    system("cls");
    if (head == nullptr) {
        cout << "\t\t\t\t\tList is empty.\n\n";
        return;
    }

    displayProducts();

    cout << "\t\t\t\t\tEnter product ID to edit: ";
    int id;
    cin >> id;

    Node* current = head;
    int position = searchProduct(id);
    int count = displayProducts();

    if (position <= count) {
        while (current->ID != id) {
            current = current->next;
        }

        cout << "\t\t\t\t\tEnter new product name (" << current->proName << "): ";
        cin.ignore();
        getline(cin, current->proName);

        cout << "\t\t\t\t\tEnter new product price (" << current->prePrice << "): ";
        cin >> current->prePrice;

        cout << "\t\t\t\t\tEnter new product quantity (" << current->quantity << "): ";
        cin >> current->quantity;

        system("cls");
        cout << "\t\t\t\t\tProduct edited successfully!\n\n";
    } else {
        cout << "\t\t\t\t\tProduct not found.\n\n";
    }
}

void printReceipt(const vector<pair<string, double>>& items, double total) {
    cout << "\t\t\t\t\tReceipt:\n";
    cout << "\t\t\t\t\t--------------------\n";
    for (const auto& item : items) {
        cout << "\t\t\t\t\t" << left << setw(20) << item.first << right << setw(10) << fixed << setprecision(2) << item.second << endl;
    }
    cout << "\t\t\t\t\t--------------------\n";
    cout << "\t\t\t\t\t" << left << setw(20) << "Total:" << right << setw(10) << fixed << setprecision(2) << total << endl;
}
// End of the program
