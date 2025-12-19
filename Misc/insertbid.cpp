#include <iostream>

const int q = 5;  // Maximum number of rows
const int m = 4;  // Number of columns

void insertRow(int A[q][m], int &n, int m, int r[], int k) {
    // Check if there's space to insert a new row
    if (n >= q) {
        std::cout << "Cannot insert new row: No space available." << std::endl;
        return;
    }

    // Shift rows downward to make space for the new row
    for (int i = n; i > k; --i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = A[i - 1][j];
        }
    }

    // Insert the new row at the specified position
    for (int j = 0; j < m; ++j) {
        A[k][j] = r[j];
    }

    // Increment the current number of rows
    ++n;
}

void printArray(int A[q][m], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int MyArray[q][m] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int currentRows = 4;

    // New row to be inserted
    int newRow[m] = {100, 101, 102, 103};
    int position = 2;  // Insert the new row at index 2 (third position)

    std::cout << "Original Array:" << std::endl;
    printArray(MyArray, currentRows, m);

    // Call the function to insert the row
    insertRow(MyArray, currentRows, 4, newRow, position);

    std::cout << "\nArray After Insertion:" << std::endl;
    printArray(MyArray, currentRows, m);

    return 0; }
