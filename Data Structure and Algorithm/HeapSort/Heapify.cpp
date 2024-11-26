//
// Created by obaidsafi31 on 11/23/24.
//
#include<iostream>
using namespace std;

// Function to maintain the max-heap property
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize the largest as the root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child is larger than root
    if (left < n && (arr[left] > arr[largest]))
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && (arr[right] > arr[largest]))
        largest = right;

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void  buildHeap(int arr[], const int n)
{
    for (int i = n/2 ; i >= 0 ; i-- )
    {
        heapify(arr, n, i);
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {12, 2, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    buildHeap(arr, n);

    cout << "Heap:\n";
    printArray(arr, n);

    return 0;
}

