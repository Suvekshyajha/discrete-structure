#include <iostream>

using namespace std;

// Function to perform linear search in an array
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    cout << "Enter the number to search: ";
    cin >> x;

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        cout << "Element is present at index " << result << endl;
    } else {
        cout << "Element is not present in the array" << endl;
    }

    return 0;
}

