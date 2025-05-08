#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int largest = arr[0], secondLargest = -1;
    int smallest = arr[0], secondSmallest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && (secondLargest == -1 || arr[i] > secondLargest)) {
            secondLargest = arr[i];
        }

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && (secondSmallest == -1 || arr[i] < secondSmallest)) {
            secondSmallest = arr[i];
        }
    }

    if (secondLargest == -1 || secondSmallest == -1) {
        cout << "No second largest or second smallest element found." << endl;
    } else {
        cout << "Second largest element: " << secondLargest << endl;
        cout << "Second smallest element: " << secondSmallest << endl;
    }

    return 0;
}
