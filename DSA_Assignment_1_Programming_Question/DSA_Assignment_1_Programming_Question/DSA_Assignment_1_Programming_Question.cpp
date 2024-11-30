
#include <iostream>

using namespace std;

#define MAX_ROWS 100
#define MAX_COLS 100


class ArrayOperations {
private:
    int AR[MAX_ROWS][MAX_COLS];
    int rows, cols;

public:
    void readArray();
    void displayArray();
    void linearSearch(int num);
    void searchMinNumber();
    void countEvenNumbers();
    void updateLocation(int row, int col, int newVal);
    void transpose();
    void multiplyWithArray(ArrayOperations B);

};

void ArrayOperations::readArray() {
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> AR[i][j];
        }
    }
}

void ArrayOperations::displayArray() {
    cout << "Array elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << AR[i][j] << " ";
        }
        cout << endl;
    }
}

void ArrayOperations::linearSearch(int num) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (AR[i][j] == num) {
                cout << "Number " << num << " found at location (" << i << ", " << j << ")" << endl;
                return;
            }
        }
    }
    cout << "Number " << num << " not found in the array" << endl;
}

void ArrayOperations::searchMinNumber() {
    int minNum = AR[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (AR[i][j] < minNum) {
                minNum = AR[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    cout << "Minimum number " << minNum << " found at location (" << minRow << ", " << minCol << ")" << endl;
}

void ArrayOperations::countEvenNumbers() {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (AR[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    cout << "Number of even numbers in the array: " << count << endl;
}

void ArrayOperations::updateLocation(int row, int col, int newVal) {
    AR[row][col] = newVal;
    cout << "Updated value at location (" << row << ", " << col << ")" << endl;
}

void ArrayOperations::transpose() {
    int transposed[MAX_COLS][MAX_ROWS];

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = AR[j][i];
        }
    }

    cout << "Transpose of the array:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

void ArrayOperations::multiplyWithArray(ArrayOperations B) {
    int C[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                C[i][j] += AR[i][k] * B.AR[k][j];
            }
        }
    }

    cout << "Result of array multiplication:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

// User Defined Function

int main() {
    ArrayOperations array;

    int choice, num, row, col, newVal;
    ArrayOperations B;

    do {
        cout << "\nPress 1 to read the contents of the array from the user" << endl;
        cout << "Press 2 to search any number and its location from the array using linear search" << endl;
        cout << "Press 3 to search the minimum number and its location from the array" << endl;
        cout << "Press 4 to count even numbers in the array" << endl;
        cout << "Press 5 to update contents of any user-defined location" << endl;
        cout << "Press 6 to find the transpose" << endl;
        cout << "Press 7 to multiply the given array with another user-defined array" << endl;
        cout << "Press 8 to quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            array.readArray();
            break;
        case 2:
            cout << "Enter the number to search: ";
            cin >> num;
            array.linearSearch(num);
            break;
        case 3:
            array.searchMinNumber();
            break;
        case 4:
            array.countEvenNumbers();
            break;
        case 5:
            cout << "Enter the row and column to update: ";
            cin >> row >> col;
            cout << "Enter the new value: ";
            cin >> newVal;
            array.updateLocation(row, col, newVal);
            break;
        case 6:
            array.transpose();
            break;
        case 7:
            cout << "Enter the elements of the second array:" << endl;
            B.readArray();
            array.multiplyWithArray(B);
            break;
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
