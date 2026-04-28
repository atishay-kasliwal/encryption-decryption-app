#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- Vigenere_Cipher class
class Vigenere_Cipher {
public:
    void run();

    void cipher(const string &text);

    void decipher(const string &text);
};

// ---------------------------------------- run
void Vigenere_Cipher::run() {
    bool check = true;
    int Choice;
    cout << "\n# ===== Welcome to Vignere Cipher ===== #" << endl;

    while (check) {
        // Showing a list for user to choose encryption or decryption
        string menu8 = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector<string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu8);


        if (Choice == 1) {                         // If he chooses encryption
            string message, result;
            cin.ignore(0, '\n');

            // To get the text and key from user
            while (true) {
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80) {
                    cipher(message);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 char
                else cout << "The input message should be restricted to 80 characters.\n";
            }
        } else if (Choice == 2) {                                // If a user chooses to decrypt
            string result, text;
            cin.ignore(0, '\n');

            while (true) {
                // Getting an Encrypted message from user
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

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

        // To see if a user wants to encrypt with the same type of cipher or no
        check = continue_or();
    }
}

// ---------------------------------------- cipher
void Vigenere_Cipher::cipher(const string &text) {
    string key, message;
    char character;
    cout << "";

    // To keep code running
    while (true) {

        // To get the key from user to encrypt it with
        cout << "Enter Your Keyword to encrypt message by it (8 chars Maximum): ";
        getline(cin, key);
        int count = 0;
        for (char i: key) {
            if (isalpha(i)) count++;
        }
        // If key is valid
        if (key.size() <= 8 && count == key.size()) {
            int num = int(text.size());
            int i = 0;
            string repeated_keyword;

            // To repeat the key to encrypt the whole text
            for (int j = 0; j < num; j++) {
                repeated_keyword += key;
                key = repeated_keyword.substr(0, num);
            }

            // Encryption process
            while (i < int(text.length())) {
//                text[i] = toupper(text[i]);
                key[i] = toupper(key[i]);

                // To check that char is alphabetic not any other chars
                if (isalpha(text[i])) {
                    int sum = int(text[i]) + int(key[i]);
                    int rem = sum % 26;
                    character = char(rem + 65);
                    message += character;
                }

                    // If char is not alphabetic
                else message += text[i];
                i++;
            }
            cout << "\nThe Encrypted Message is: " << message << endl;
            break;
        }

            // If key is more than 8 characters
        else cout << "The input message should be restricted to 8 characters.\n";
    }
}

// ---------------------------------------- decipher
void Vigenere_Cipher::decipher(const string &text) {
    string key, message;
    int sum = 0;
    char character;

    // To keep code running
    while (true) {
        // To get key from user to decrypt the message
        cout << "Enter Your Keyword to decrypt the text (80 char Maximum): ";
        getline(cin, key);
        int count = 0;
        for (char i: key) {
            if (isalpha(i)) count++;
        }

        // To check that size of key is less than 8
        if (key.size() <= 8 && count == key.size()) {
            int num = int(text.size());
            int i = 0;
            string repeated_keyword;

            // To repeat the key to encrypt the whole text
            for (int j = 0; j < num; j++)
                repeated_keyword += key;
            key = repeated_keyword.substr(0, num);

            // Decryption process
            while (i < int(text.length())) {
//                text[i] = toupper(text[i]);
                key[i] = toupper(key[i]);

                // If the char is alphabetic
                if (isalpha(text[i])) {
                    int rem = int(text[i]) - 65;
                    for (int h = 0; h < 243; h++) {
                        if (h % 26 == rem) {
                            if (h - key[i] <= 90 && h - key[i] >= 65)
                                sum = h;
                        }
                    }
                    character = char(sum - int(key[i]));
                    message += character;
                }

                    // If it is not alphabetic
                else message += text[i];
                i++;
            }
            cout << "\nThe Original Message is: " << message << endl;
            break;
        }

            // If key size is more than 8 chars
        else cout << "The input message should be restricted to 8 characters.\n";
    }
}

#endif
