#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- helper functions
// Check if the input has any character except alphabet for Atbash, and Simple Substitution.
void validity(string &text) {
    while (true) {
        int count = 0;
        while (text.empty()) {
            cout << "Invalid Input." << endl;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++) {
            if (isalpha(text[i])) count++;
            else {
                cout << "Invalid Input." << endl;
                cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())) break;

    }
}

// ---------------------------------------- Atbash_Cipher class
class Atbash_Cipher {
public:
    void run();

    string cipher(string &text, int choice);

    string decipher(string &text, int choice);
};

// ---------------------------------------- run
void Atbash_Cipher::run() {
    cout << "\n# ===== Welcome to Atbash Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        // Print the menu and check the validity of choice
        string menu2 = "What do you want to do?\n [1] Encrypt a message.\n [2] Decrypt a message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector<string> choices = {"1", "2", "3"};
        int choice = menu_check(choices, menu2);

        // Print the menu and check the validity of choice and encrypt a message
        if (choice == 1) {
            string menu = "What do you want to do?\n [1] Encrypt a message on the whole alphabet.\n [2] Encrypt a message on half alphabet.\n [3] Back.\nEnter Your Choice: ";
            int choice3 = menu_check(choices, menu);

            string text;
            if (choice3 == 1 || choice3 == 2) {
                cout << "Please enter the message you want to encrypt: ";
                getline(cin, text);
                cout << "The Encrypted Message is: " << cipher(text, choice3) << endl;
            }
        }
            // Print the menu and check the validity of choice and decrypt a message
        else if (choice == 2) {
            string menu4 = "What do you want to do?\n [1] Decrypt a message on the whole alphabet.\n [2] Decrypt a message on half alphabet.\n [3] Back.\nEnter Your Choice:";
            int choice2 = menu_check(choices, menu4);

            string text;
            if (choice2 == 1 || choice2 == 2) {
                cout << "Please enter the message you want to decrypt: ";
                getline(cin, text);
                cout << "The Decrypted Message is: " << decipher(text, choice2) << endl;
            }

        }
            // Exit the cipher
        else if (choice == 3) break;

        // To see if user wants to encrype with the same type of cipher or no
        check = continue_or();
    }
    return;
}

// ---------------------------------------- cipher
string Atbash_Cipher::cipher(string &text, int choice) {
    string result;
    validity(text);
    for (char character: text) {

        // Encrypt a message on the whole letters of the alphabet
        if (choice == 1) {
            // Check if the letter is uppercase to encrypt
            if (isupper(character)) {
                result += static_cast<char>(25 + 130 - static_cast<int>(character));
            }

                // Check if the letter is lowercase to encrypt
            else if (islower(character)) {
                result += static_cast<char>(25 + 194 - static_cast<int>(character));
            }
        }

            // Encrypt a message on half-letters of the alphabet
        else if (choice == 2) {
            // Check if the letter is uppercase to encrypt
            int digit = static_cast<int>(character);
            if (isupper(character)) {
                if (digit <= 77) {
                    result += static_cast<char>(12 + 130 - static_cast<int>(character));
                } else if (digit > 77) {
                    result += static_cast<char>(12 + 156 - static_cast<int>(character));
                }
            }

                // Check if the letter is lowercase to encrypt
            else if (islower(character)) {
                if (digit <= 109) {
                    result += static_cast<char>(12 + 194 - static_cast<int>(character));
                } else if (digit > 109) {
                    result += static_cast<char>(12 + 220 - static_cast<int>(character));
                }
            }
        }
    }
    return result;
}

// ---------------------------------------- decipher
string Atbash_Cipher::decipher(string &text, int choice) {
    string result;
    validity(text);
    for (char character: text) {
        // Decrypt a message on the whole letters of the alphabet
        if (choice == 1) {
            // Check if the letter is uppercase to decrypt
            if (isupper(character)) {
                result += static_cast<char>(25 + 130 - static_cast<int>(character));
            }

                // Check if the letter is lowercase to decrypt
            else if (islower(character)) {
                result += static_cast<char>(25 + 194 - static_cast<int>(character));
            }
        }

            // Decrypt a message on half-letters of the alphabet
        else if (choice == 2) {
            // Check if the letter is uppercase to decrypt
            int digit = static_cast<int>(character);
            if (isupper(character)) {
                if (digit <= 77) {
                    result += static_cast<char>(12 + 130 - static_cast<int>(character));
                } else if (digit > 77) {
                    result += static_cast<char>(12 + 156 - static_cast<int>(character));
                }
            }

                // Check if the letter is lowercase to decrypt
            else if (islower(character)) {
                if (digit <= 109) {
                    result += static_cast<char>(12 + 194 - static_cast<int>(character));
                } else if (digit > 109) {
                    result += static_cast<char>(12 + 220 - static_cast<int>(character));
                }
            }
        }
    }
    return result;
}

#endif
