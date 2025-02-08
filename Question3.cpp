#include <iostream>

using namespace std;

int main() {
    char str[100], cleanStr[100], freq[256] = {0};
    int len = 0, cleanLen = 0, isPalindrome = 1;
    
    cout << "Enter a string: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            char ch = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + 32) : str[i];
            cleanStr[cleanLen++] = ch;
            freq[ch]++;
        }
    }
    cleanStr[cleanLen] = '\0';

    for (int i = 0; i < cleanLen / 2; i++) {
        if (cleanStr[i] != cleanStr[cleanLen - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) cout << "The string is a palindrome." << endl;
    else cout << "The string is not a palindrome." << endl;

    cout << "Character frequencies:" << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) {
            cout << char(i) << ": " << (int)freq[i] << endl;
        }
    }

    cout << "String after replacing vowels with '*': ";
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + 32) : str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cout << '*';
        else cout << str[i];
    }
    cout << endl;

    return 0;
}