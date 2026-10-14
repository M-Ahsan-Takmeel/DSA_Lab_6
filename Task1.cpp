
#include <iostream>
using namespace std;

const int MAX = 100;

int inputIDs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return n;
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void displayResult(int index) {
    if (index != -1) {
        cout << "Student ID found at index " << index << endl;
    } else {
        cout << "Student ID is not registered." << endl;
    }
}

int main() {
    int arr[MAX];
    int n, target;

    cout << "Enter number of students (0-100): ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid number of students." << endl;
        return 0;
    }
    cout << "Enter student IDs: ";
    inputIDs(arr, n);
    cout << "Enter target student ID: ";
    cin >> target;
    int index = linearSearch(arr, n, target);
    displayResult(index);
    return 0;
}
