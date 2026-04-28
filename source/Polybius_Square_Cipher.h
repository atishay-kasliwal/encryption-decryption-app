#ifndef POLYBIUS_SQUARE_CIPHER_H
#define POLYBIUS_SQUARE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- Polybius_Square_Cipher class
class Polybius_Square_Cipher {
public:
    void run();

    void cipher(const string &text);

    void decipher(const string &text);
};

// ---------------------------------------- run
void Polybius_Square_Cipher::run() {
    int Choice;
    cout << "\n# ===== Welcome to Polybius Square Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        // Showing a list for user to choose encryption or decryption
        string menu5 = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector<string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu5);

        if (Choice == 1) {                                   // If he chooses encryption
            string message, result;
            cin.ignore(0, '\n');

            // To get the text and key from user
            while (true) {
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80) {
                    cout << endl;
                    cipher(message);
                    cout << endl << endl;
                    break;
                }

                    // If it is more than 80 char
                else cout << "The input message should be restricted to 80 characters.\n";
            }
        } else if (Choice == 2) {                                // If the user chooses to decrypt
            string result, text;
            cin.ignore(0, '\n');

            while (true) {
                // Getting an Encrypted message from user
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that the input contains digits and spaces or not
                while (true) {
                    int count = 0;
                    for (char character: result) {
                        if (isdigit(character) || isspace(character)) count++;
                    }

                    if (count == result.size()) break;
                    else {
                        cout << "The input should be only digits and spaces." << endl;
                        cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                        getline(cin, result);
                    }
                }

                // To check that text size is less than 80 chars and decrypt it
                if (result.size() <= 80) {
                    decipher(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars
                else cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher
        else if (Choice == 3) return;

        // To see if user wants to encrype with the same type of cipher or no
        cin.ignore(1, '\n');
        check = continue_or();
    }
}

// ---------------------------------------- cipher
void Polybius_Square_Cipher::cipher(const string &text) {
    int arr[5];
    for (int &j: arr) {
        cout << "Enter Your Keyword: ";
        cin >> j;
    }
    string result;
    cout << "\nThe Encrypted Message is: ";
    for (char i: text) {
        i = toupper(i);
        if (isalpha(i)) {
            if (i == 'A') { cout << arr[0] << arr[0]; }
            else if (i == 'B') { cout << arr[0] << arr[1]; }
            else if (i == 'C') { cout << arr[0] << arr[2]; }
            else if (i == 'D') { cout << arr[0] << arr[3]; }
            else if (i == 'E') { cout << arr[0] << arr[4]; }
            else if (i == 'F') { cout << arr[1] << arr[0]; }
            else if (i == 'G') { cout << arr[1] << arr[1]; }
            else if (i == 'H') { cout << arr[1] << arr[2]; }
            else if (i == 'I') { cout << arr[1] << arr[3]; }
            else if (i == 'J') { cout << arr[1] << arr[3]; }
            else if (i == 'K') { cout << arr[1] << arr[4]; }
            else if (i == 'L') { cout << arr[2] << arr[0]; }
            else if (i == 'M') { cout << arr[2] << arr[1]; }
            else if (i == 'N') { cout << arr[2] << arr[2]; }
            else if (i == 'O') { cout << arr[2] << arr[3]; }
            else if (i == 'P') { cout << arr[2] << arr[4]; }
            else if (i == 'Q') { cout << arr[3] << arr[0]; }
            else if (i == 'R') { cout << arr[3] << arr[1]; }
            else if (i == 'S') { cout << arr[3] << arr[2]; }
            else if (i == 'T') { cout << arr[3] << arr[3]; }
            else if (i == 'U') { cout << arr[3] << arr[4]; }
            else if (i == 'V') { cout << arr[4] << arr[0]; }
            else if (i == 'W') { cout << arr[4] << arr[1]; }
            else if (i == 'X') { cout << arr[4] << arr[2]; }
            else if (i == 'Y') { cout << arr[4] << arr[3]; }
            else if (i == 'Z') { cout << arr[4] << arr[4]; }
        } else if (isspace(i)) { cout << " "; }
    }
    cout << result;
}

// ---------------------------------------- decipher
void Polybius_Square_Cipher::decipher(const string &text) {
    int arr[5];
    for (int &j: arr) {
        cout << "Enter Your Keyword: ";
        cin >> j;
    }
    string result;

    for (int i = 0; i < int(text.size());) {
        if (isdigit(text[i]) && isdigit(text[i + 1])) {
            if (text.substr(i, 2) == to_string(arr[0]) + to_string(arr[0])) { result += 'A'; }
            else if (text.substr(i, 2) == to_string(arr[0]) + to_string(arr[1])) { result += 'B'; }
            else if (text.substr(i, 2) == to_string(arr[0]) + to_string(arr[2])) { result += 'C'; }
            else if (text.substr(i, 2) == to_string(arr[0]) + to_string(arr[3])) { result += 'D'; }
            else if (text.substr(i, 2) == to_string(arr[0]) + to_string(arr[4])) { result += 'E'; }
            else if (text.substr(i, 2) == to_string(arr[1]) + to_string(arr[0])) { result += 'F'; }
            else if (text.substr(i, 2) == to_string(arr[1]) + to_string(arr[1])) { result += 'G'; }
            else if (text.substr(i, 2) == to_string(arr[1]) + to_string(arr[2])) { result += 'H'; }
            else if (text.substr(i, 2) == to_string(arr[1]) + to_string(arr[3])) { result += 'I'; }
            else if (text.substr(i, 2) == to_string(arr[1]) + to_string(arr[4])) { result += 'K'; }
            else if (text.substr(i, 2) == to_string(arr[2]) + to_string(arr[0])) { result += 'L'; }
            else if (text.substr(i, 2) == to_string(arr[2]) + to_string(arr[1])) { result += 'M'; }
            else if (text.substr(i, 2) == to_string(arr[2]) + to_string(arr[2])) { result += 'N'; }
            else if (text.substr(i, 2) == to_string(arr[2]) + to_string(arr[3])) { result += 'O'; }
            else if (text.substr(i, 2) == to_string(arr[2]) + to_string(arr[4])) { result += 'P'; }
            else if (text.substr(i, 2) == to_string(arr[3]) + to_string(arr[0])) { result += 'Q'; }
            else if (text.substr(i, 2) == to_string(arr[3]) + to_string(arr[1])) { result += 'R'; }
            else if (text.substr(i, 2) == to_string(arr[3]) + to_string(arr[2])) { result += 'S'; }
            else if (text.substr(i, 2) == to_string(arr[3]) + to_string(arr[3])) { result += 'T'; }
            else if (text.substr(i, 2) == to_string(arr[3]) + to_string(arr[4])) { result += 'U'; }
            else if (text.substr(i, 2) == to_string(arr[4]) + to_string(arr[0])) { result += 'V'; }
            else if (text.substr(i, 2) == to_string(arr[4]) + to_string(arr[1])) { result += 'W'; }
            else if (text.substr(i, 2) == to_string(arr[4]) + to_string(arr[2])) { result += 'X'; }
            else if (text.substr(i, 2) == to_string(arr[4]) + to_string(arr[3])) { result += 'Y'; }
            else if (text.substr(i, 2) == to_string(arr[4]) + to_string(arr[4])) { result += 'Z'; }
            i += 2;
        } else if (isspace(text[i])) {
            result += " ";
            i++;
        }
    }
    cout << "\nThe Original Message is: " << result << endl;
}

#endif
