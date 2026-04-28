#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- helper functions
// To check that key is a number.
int check_number(const string &print) {
    string key;
    while (true) {
        bool check = true;
        cout << print;
        getline(cin, key);
        for (char character: key) {
            if (!isdigit(character) || stoll(key) < 0) break;
        }

        if (check) return stoll(key);
        else cout << "Please enter a valid number" << endl;
    }
}

// Defining a function for all the menus.
int menu_check(const vector<string> &choices, const string &menu) {
    string choice;
    while (true) {
        cout << menu;
        getline(cin, choice);
        for (const auto &i: choices) {
            if (choice == i) {
                cin.ignore(0, '\n');
                return stoi(choice);
            }
        }
        cout << "Please enter a valid choice." << endl << endl;
    }
}

// To see if user wants to continue.
bool continue_or() {
    string choice;
    while (true) {
        cout << "Do you want to continue in this cipher?\n [1] Yes.\n [2] No.\nEnter Your Choice :";
        getline(cin, choice);

        if (choice == "1") {
            cout << endl;
            return true;
        } else if (choice == "2") {
            cout << endl;
            return false;
        } else cout << "Please enter a valid input." << endl;
    }
}

// ---------------------------------------- Affine_Cipher class
class Affine_Cipher {
public:
    void run();

    void cipher();

    void decipher();
};

// ---------------------------------------- run
void Affine_Cipher::run() {
    int choice;
    bool check = true;
    while (check) {
        string menu;
        cout << "\n# ===== Welcome to Affine Cipher ===== #" << endl;
        menu = "What will you do ?\n [1] Ciphering Text.\n [2] Deciphering Text.\n [3] Exit This Cipher.\nEnter Your Choice :";
        vector<string> choices = {"1", "2", "3"};
        choice = menu_check(choices, menu);

        if (choice == 1) cipher();                  // Encryption Process of Affine Cipher.
        else if (choice == 2) decipher();            // Decryption Process of Affine Cipher.
        else if (choice == 3) return;
        check = continue_or();
    }
}

// ---------------------------------------- cipher
void Affine_Cipher::cipher() {
    int a, b, c;
    string menu, text, result;
    cout << "Enter the Text you want to encrypt : ";
    getline(cin, text);
    a = check_number("Enter the number (a) to encrypt (the form of encryption is (a*(char Ascii value)+ b) % 26) : ");
    b = check_number("enter the number (b) to encrypt (the form of encryption is (a*(char Ascii value)+ b) % 26) : ");
    cout << endl
         << "Note the form of encryption is (a*(char Ascii value)+b) \nthe form of decryption is (c* (char ascii value - b )) \nwhere (a * c) % 26 must equal 1 for right encryption and decryption"
         << endl << endl;

    for (char i: text) {
        if (isalpha(i))
            result += char(((a * (toupper(i) - 'A') + b) % 26) + 'A');
        else
            result += i;
    }
    cout << "The Encryption of your text : " << result << endl;
}

// ---------------------------------------- decipher
void Affine_Cipher::decipher() {
    int a, b, c;
    string menu, text, result;
    cout << "Enter the Text you want to decrypt : ";
    getline(cin, text);
    c = check_number("Enter the number (c) to decrypt (the form of encryption is (c*(char Ascii value- b) % 26) : ");
    b = check_number("enter the number (b) to encrypt (the form of encryption is (c*(char Ascii value- b) % 26) : ");
    cout << endl
         << "Note the form of encryption is (a*(char Ascii value)+b) \nthe form of decryption is (c* (char ascii value - b )) \nwhere (a * c) % 26 must equal 1 for right encryption and decryption"
         << endl << endl;

    for (char i: text) {
        if (isalpha(i)) {
            int sum = (c * ((toupper(i) - 'A') - b)) % 26;
            if (sum < 0)
                sum += 26;
            result += char(sum + 'A');
        } else
            result += i;
    }
    cout << "The Decryption of your message: " << result << endl;
}

#endif