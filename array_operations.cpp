// array_operations.cpp
#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum array size

// Function to insert an element at a given position
int insertElement(int arr[], int& size, int element, int position) {
    if (size >= MAX_SIZE || position < 0 || position > size) {
        return -1; // Error: Array full or invalid position
    }
    for (int i = size; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    size++;
    return 0; // Success
}

// Function to delete an element at a given position
int deleteElement(int arr[], int& size, int position) {
    if (size <= 0 || position < 0 || position >= size) {
        return -1; // Error: Array empty or invalid position
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return 0; // Success
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insertion
    if (insertElement(arr, size, 10, 2) == 0) {
        cout << "Array after insertion: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Insertion failed." << endl;
    }

    // Deletion
    if (deleteElement(arr, size, 3) == 0) {
        cout << "Array after deletion: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Deletion failed." << endl;
    }

    return 0;
}