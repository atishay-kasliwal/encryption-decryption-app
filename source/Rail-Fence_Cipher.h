#ifndef RAILFENCE_CIPHER_H
#define RAILFENCE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- helper functions
// Remove spaces and return it in lower case.
string remove_space(const string &str) {
    string result;
    for (char ch: str) {
        if (!isspace(ch)) result += tolower(ch);
    }
    return result;
}

// ---------------------------------------- RailFence_Cipher class
class RailFence_Cipher {
public:
    void run();

    void cipher();

    void decipher();
};

// ---------------------------------------- run
void RailFence_Cipher::run() {
// To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Rail-Fence Cipher ===== #" << endl;
    bool firstCheck = true;
    while (firstCheck) {
        string menu10 = "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit This Cipher.\nEnter Your choice: ";
        vector<string> choices = {"1", "2", "3"};
        int choice = menu_check(choices, menu10);

        if (choice == 1) cipher();                                   // If he chooses to encrypt
        else if (choice == 2) decipher();                              // If he chooses to decrypt

        else if (choice == 3) return;         // Exit

        cout << endl;
        // To see if user wants to encrype with the same type of cipher or no
        firstCheck = continue_or();
    }
}

// ---------------------------------------- cipher
void RailFence_Cipher::cipher() {
// To get the sentence and the key from user
    string text;
    int key, counter = 0, num = 0;
    bool check = false;

    cout << "Enter sentence you want to encrypt: ";
    getline(cin, text);
    text = remove_space(text);
    key = check_number("Enter the key you want to encrypt by :");
    char arr[key][text.length()];

    // To fill the 2D array with points to simplify it
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++)
            arr[i][j] = '.';
    }

    // To make the rail fence of the sentence
    for (int i = 0; i < int(text.size()); i++) {
        arr[num][i] = text[i];
        if (!check)
            num++;
        else
            num--;
        if ((num % (key - 1) == 0 && i != 0 && key > 2) || ((num == 1 || num == 0) && key <= 2))
            check = !check;
    }

    // Print the process that is done
    cout << "\n==== Encryption Process... ====" << endl;
    // To print the 2D array
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++)
            cout << arr[i][j];
        cout << endl;
    }

    // To print the encrypted code
    cout << "\nThe Encryption of your sentence is: ";
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++) {
            if (arr[i][j] != '.')
                cout << arr[i][j];
        }
    }
    cout << endl;
}

// ---------------------------------------- decipher
void RailFence_Cipher::decipher() {
// To get the sentence and the key from user
    string text;
    int key, counter = 0, num = 0;
    bool check = false;

    cout << "Enter sentence you want to decrypt: ";
    getline(cin, text);
    text = remove_space(text);
    key = check_number("Enter the key you want to decrypt text by");
    char arr[key][text.length()];

    // To fill the 2D array with points to simplify it
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++)
            arr[i][j] = '.';
    }

    // To identify the place of characters in the rail fence to declare it
    for (int i = 0; i < int(text.size()); i++) {
        arr[num][i] = '#';

        if (!check) num++;
        else num--;

        if ((num % (key - 1) == 0 && i != 0 && key > 2) || ((num == 1 || num == 0) && key <= 2))
            check = !check;
    }

    // To declare it by arranging the characters
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++) {
            if (arr[i][j] != '.') {
                arr[i][j] = text[counter];
                counter++;
            }
        }
    }

    cout << "\n==== Decryption Process... ====" << endl;
    // To print the 2D array
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < int(text.length()); j++)
            cout << arr[i][j];
        cout << endl;
    }

    // To print the text in its normal state after declaration
    cout << "\nThe Decription of your text: ";
    for (int i = 0; i < int(text.length()); i++) {
        for (int j = 0; j < key; j++) {
            if (arr[j][i] != '.')
                cout << arr[j][i];
        }
    }
    cout << endl;
}

#endif
