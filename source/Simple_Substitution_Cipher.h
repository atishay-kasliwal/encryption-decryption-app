#ifndef SIMPLE_SUBSTITUTION_CIPHER_H
#define SIMPLE_SUBSTITUTION_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- helper functions
// Check if the input has any character except alphabet, and it is 5 digits.
void validity2(string &text) {
    while (true) {
        int count = 0;
        while (text.size() != 5) {
            cout << "Invalid Input." << endl;
            cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++) {
            for (int j = 0; j < int(text.size()); j++) {
                if (isalpha(text[i]) && (text[i] != text[j]))
                    count++;
            }
        }

        if (count == 20) break;
        else {
            cout << "Invalid Input." << endl;
            cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
            getline(cin, text);
        }
    }
}

// ---------------------------------------- Simple_Substitution_Cipher class
class Simple_Substitution_Cipher {
public:
    void run();

    string cipher(string &text, const string &keyword);

    string decipher(string &text, const string &keyword);
};

// ---------------------------------------- run
void Simple_Substitution_Cipher::run() {
    cout << "\n# ===== Welcome to Simple Substitution Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        // Print the menu and check the validity of choice
        string menu4 = "What do you want to do?\n [1] Encrypt a message.\n [2] Decrypt a message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector<string> choices = {"1", "2", "3"};
        int choice = menu_check(choices, menu4);

        // Get the message and encrypt messages
        if (choice == 1) {
            string text, keyword;
            cout << "Please enter the message you want to encrypt: ";
            getline(cin, text);
            validity(text);
            cout << "Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "\nThe Encrypted Message is: " << cipher(text, keyword) << endl << endl;
        }

            // Get the message and decrypt messages
        else if (choice == 2) {
            string text, keyword;
            cout << "Please enter the message you want to decrypt: ";
            getline(cin, text);
            validity(text);
            cout << "Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "\nThe Decrypted Message is: " << decipher(text, keyword) << endl << endl;
        }
            // Exit the cipher
        else if (choice == 3) break;

        // To see if user wants to encrype with the same type of cipher or no
        check = continue_or();
    }
}

// ---------------------------------------- cipher
string Simple_Substitution_Cipher::cipher(string &text, const string &keyword) {
    string result, text2, keyword2;
    deque<char> alphabet, key, new_alphabet;

    // Convert the message and keyword into uppercase
    for (char character: text) {
        text2 += toupper(character);
    }
    for (char character: keyword) {
        keyword2 += toupper(character);
    }
    // Make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        alphabet.push_back(static_cast<char>(i));
    }
    for (char character: keyword2) {
        key.push_back(character);
        new_alphabet.push_back(character);
    }
    for (char character: alphabet) {
        if (find(key.begin(), key.end(), character) == key.end())
            new_alphabet.push_back(character);
    }
    for (char character: text2) {
        if (isalpha(character))
            result += new_alphabet[static_cast<int>(character) - 65];
    }
    return result;
}

// ---------------------------------------- decipher
string Simple_Substitution_Cipher::decipher(string &text, const string &keyword) {
    string result, text2, keyword2;
    deque<char> alphabet, key, new_alphabet;

    // Convert the message and keyword into uppercase
    for (char character: text) {
        text2 += toupper(character);
    }
    for (char character: keyword) {
        keyword2 += toupper(character);
    }
    // Make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        alphabet.push_back(static_cast<char>(i));
    }
    for (char character: keyword2) {
        key.push_back(character);
        new_alphabet.push_back(character);
    }
    for (char character: alphabet) {
        if (find(key.begin(), key.end(), character) == key.end())
            new_alphabet.push_back(character);
    }
    for (char character: text2) {
        for (int j = 0; j < int(new_alphabet.size()); j++) {
            if (character == new_alphabet[j])
                result += alphabet[j];
        }
    }
    return result;
}

#endif
