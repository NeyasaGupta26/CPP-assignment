#include <iostream>

using namespace std;

int main() {
    int n, prime = 1;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 2) prime = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime = 0;
            break;
        }
    }

    if (prime == 1) {
        int next = n + 1;
        while (true) {
            int isPrime = 1;
            for (int i = 2; i * i <= next; i++) {
                if (next % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime == 1) {
                cout << "Next prime number: " << next << endl;
                break;
            }
            next++;
        }
    } else {
        cout << "Factors of " << n << " are: ";
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
