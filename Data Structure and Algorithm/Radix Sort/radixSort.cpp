//
// Created by obaidsafi31 on 11/16/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to perform counting sort on a specific character position
void countingSortByCharacter(vector<string>& arr, int position) {
    int range = 256; // ASCII character range
    vector<int> count(range, 0);
    vector<string> output(arr.size());

    // Count occurrences of each character at the given position
    for (const string& str : arr) {
        count[str[position]]++;
    }

    // Update the count array to store cumulative sums
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) { // Traverse in reverse for stability
        char charAtPos = arr[i][position];
        output[count[charAtPos] - 1] = arr[i];
        count[charAtPos]--;
    }

    // Copy the sorted strings back to the original array
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort on strings
void radixSortStrings(vector<string>& arr) {
    if (arr.empty()) return;

    // Determine the maximum string length
    size_t maxLength = 0;
    for (const string& str : arr) {
        maxLength = max(maxLength, str.length());
    }

    // Pad strings with spaces to ensure equal length
    for (string& str : arr) {
        str.append(maxLength - str.length(), ' ');
    }

    // Sort by each character position from rightmost to leftmost
    for (int position = maxLength - 1; position >= 0; position--) {
        countingSortByCharacter(arr, position);
    }

    // Remove padding spaces
    for (string& str : arr) {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
    }
}

int main() {
    // Example input
    vector<string> strings = {"cat", "bat", "rat", "mat", "fat", "hat"};

    // Perform Radix Sort
    radixSortStrings(strings);

    // Output the sorted array
    cout << "Sorted Strings:" << endl;
    for (const string& str : strings) {
        cout << str << endl;
    }

    return 0;
}
