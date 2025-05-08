#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    int arr[n][n];

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Rotated matrix (90 degrees clockwise):" << endl;
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
