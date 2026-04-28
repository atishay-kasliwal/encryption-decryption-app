#ifndef ROUTE_CIPHER_H
#define ROUTE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- Route_Cipher class
class Route_Cipher {
public:
    void run();

    void cipher(const string &text);

    void decipher(const string &text);
};

// ---------------------------------------- run
void Route_Cipher::run() {
    int Choice;
    cout << "\n# ===== Welcome to Route Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        // Showing a list for user to choose encryption or decryption.
        string menu = "What will you do ?\n [1] Ciphering Text.\n [2] Deciphering Text.\n [3] Exit This Cipher.\nEnter Your Choice :";
        vector<string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu);

        if (Choice == 1) {                         // If he chooses encryption.
            string message, result;
            cin.ignore(0, '\n');

            // To get the text and key from the user.
            while (true) {
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit.
                if (message.size() <= 80) {
                    cipher(message);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 char.
                else cout << "The input message should be restricted to 80 characters.\n";
            }
        } else if (Choice == 2) {                                // If a user chooses to decrypt.
            string result, text;
            cin.ignore(0, '\n');

            while (true) {
                // Getting an Encrypted message from user.
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that text size is less than 80 chars and decrypt it.
                if (result.size() <= 80) {
                    decipher(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars.
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher.
        else if (Choice == 3) {
            cout << endl;
            return;
        }

        // To see if a user wants to encrypt with the same type of cipher or no.
        cin.ignore(1, '\n');
        check = continue_or();
    }
}

// ---------------------------------------- cipher
void Route_Cipher::cipher(const string &text) {
    string new_text, result;
    cout << "Enter Your Key: ";
    int key;
    cin >> key;

    for (char i: text) {
        if (isalpha(i)) new_text += i;
    }
    while (key < 2) {
        cout << "Invalid Input.\nEnter Your Key: ";
        cin >> key;
    }
    int num = int(new_text.size());
    if (num % key == 0) {
        char matrix[text.size()], arr[num][key];
        for (int i = 0; i < int(text.size()); i++) {
            matrix[i] = new_text[i];
        }

        // 2D Matrix
        int m = 0;
        for (int row = 0; row < num; row++) {
            for (int col = 0; col < key; col++) {
                matrix[m] = toupper(matrix[m]);
                arr[row][col] = matrix[m];
                m++;
            }
        }

        int i, k = 0, l = 0, n = key;
        m = new_text.size() / key;
        // k --> starting row index, m --> ending row index.
        // l --> starting column index, n --> ending column index.
        // i --> iterator.
        string res;
        while (k < m && l < n) {
            // Print the last column from the remaining columns
            for (i = k; i < m; ++i) {
                res += arr[i][n - 1];
            }
            n--;

            // Print the last row from the remaining rows
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    res += arr[m - 1][i];
                }
                m--;
            }
            // Print the first column from the remaining columns
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    res += arr[i][l];
                }
                l++;
            }

            // Print the first row from the remaining rows
            for (i = l; i < n; ++i) {
                res += arr[k][i];
            }
            k++;
        }
        cout << "\nThe Encrypted Message is: " << res << endl;
    } else {
        char matrix[key * ((num / 2) + 1)], arr[(num / 2) + 1][key];
        int j = int(new_text.size());
        while (j < key * ((num / key) + 1)) {
            new_text.push_back('X');
            j++;
        }
        cout << new_text << endl;
        for (int i = 0; i < key * (num + 1); i++) {
            matrix[i] = new_text[i];
        }

        //2D Matrix
        int m = 0;
        for (int row = 0; row < num + 1; row++) {
            for (int col = 0; col < key; col++) {
                matrix[m] = toupper(matrix[m]);
                arr[row][col] = matrix[m];
                m++;
            }
        }

        int i, k = 0, l = 0, n = key;
        m = new_text.size() / key;
        // k --> starting row index, m --> ending row index.
        // l --> starting column index, n --> ending column index.
        // i --> iterator.
        string res;
        while (k < m && l < n) {

            // Print the last column from the remaining columns
            for (i = k; i < m; ++i) {
                res += arr[i][n - 1];
            }
            n--;

            // Print the last row from the remaining rows
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    res += arr[m - 1][i];
                }
                m--;
            }

            // Print the first column from the remaining columns
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    res += arr[i][l];
                }
                l++;
            }

            // Print the first row from the remaining rows
            for (i = l; i < n; ++i) {
                res += arr[k][i];
            }
            k++;
        }
        cout << "\nThe Encrypted Message is: " << res.substr(0, key * ((num / key) + 1)) << endl;
    }
}

// ---------------------------------------- decipher
void Route_Cipher::decipher(const string &text) {
    string new_text, result;
    int key;
    cout << "Enter Your Key: ";
    cin >> key;

    for (char character: text) {
        if (isalpha(character)) new_text += character;
    }
    while (key < 2 || key > new_text.size() / 2) {
        cout << "Invalid Input.\nEnter Your Key: ";
        cin >> key;
    }
}

#endif
