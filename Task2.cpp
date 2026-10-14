#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

vector<int> inputSortedIDs(int n) {
    vector<int> arr(n);
    if (n > 0) {
        cout << "Enter " << n << " registration IDs in ascending order:\n";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }
    return arr;
}

int binarySearch(const vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void displayResult(int index) {
    if (index != -1) {
        cout << "ID found at Index " << index << "\n";
    } else {
        cout << "ID is not registered.\n";
    }
}

int main() {
    int n, target;
    cout << "Enter the number of students (0 for empty array): ";
    cin >> n;
    vector<int> studentIDs = inputSortedIDs(n);
    if (n > 0 && !isSorted(studentIDs, n)) {
        cout << "Error: The input array is not sorted. Binary search requires sorted data.\n";
        return 1;
    }
    cout << "Enter target ID to search: ";
    cin >> target;
    int resultIndex = binarySearch(studentIDs, 0, n - 1, target);
    displayResult(resultIndex);
    return 0;
}