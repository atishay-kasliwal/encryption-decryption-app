#ifndef BACONIAN_CIPHER_H
#define BACONIAN_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- helper functions
// Check if the input has any character except A, B, a or b.
string validity1(string &text) {
    while (true) {
        int count = 0;

        for (int i = 0; i < int(text.size()); i++) {
            if (text[i] != 'A' && text[i] != 'B' && text[i] != 'a' && text[i] != 'b' && !isspace(text[i])) {
                cout << "Invalid input." << endl;
                cout << "Please enter the message to decrypt that only contain A, B, a or b.: ";
                cin >> text;
                break;
            } else count++;
        }
        if (count == int(text.size())) break;
    }
    return text;
}

// ---------------------------------------- Baconian_Cipher class
class Baconian_Cipher {
public:
    void run();

    string cipher(const string &text);

    string decipher(const string &text);
};

// ---------------------------------------- run
void Baconian_Cipher::run() {
    // To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Baconian Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        string menu3 = "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit This Cipher.\nEnter Your Choice: ";
        int main4;
        vector<string> choices = {"1", "2", "3"};
        main4 = menu_check(choices, menu3);

        // Check if the user wants to enter a message to encrypt
        if (main4 == 1) {
            string text;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);

            // Check if the input has any character except alphabet
            while (true) {
                bool flag = false;
                for (char character: text) {
                    if (!isalpha(character) && !isspace(character)) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    cout << "Invalid Input." << endl;
                    cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                    getline(cin, text);
                } else break;
            }

            // Print the encrypted message
            cout << "\nThe Encrypted Message is: " << cipher(text) << endl << endl;
        }

            // Check if the user wants to enter a message to decrypt
        else if (main4 == 2) {
            string text;
            cout << "Please enter the message to decrypt that only contains A, B, a or b.: ";
            getline(cin, text);
            validity1(text);

            // Print the decrypted message
            cout << "\nThe Decrypted Message is: " << decipher(text) << endl << endl;
        }

            // Back to the main menu
        else if (main4 == 3) break;

        // To see if user wants to encrype with the same type of cipher or no
        string menu10 = "Do you want to continue with same cipher?\n [1] Yes. \n [2] No. \nEnter Your Choice : ";
        vector<string> choices10 = {"1", "2"};
        int num = menu_check(choices10, menu10);
        if (num == 2) {
            check = false;
            cout << endl;
        }
    }
}

// ---------------------------------------- cipher
string Baconian_Cipher::cipher(const string &text) {
    deque<string> elements;
    string old_result, result;

    // Make a deque that contain binary conversion to elements from A to Z
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
        int digit = 0;
        string digit2;
        digit = i - 65;
        bitset<5> binary(digit);
        digit2 = binary.to_string();
        elements.push_back(digit2);
    }

    // Convert all characters into uppercase and add the opposite index to each character in elements deque from A to Z to old_result
    for (char character: text) {
        int digit = 0;
        char index;
        index = toupper(character);
        digit = static_cast<int>(index) - 65;
        old_result += elements[digit];
    }

    // Convert every '1' to b and every '0' to a then add it to result
    for (char character: old_result) {
        if (character == '1') result += 'b';
        else if (character == '0') result += 'a';
    }
    return result;
}

// ---------------------------------------- decipher
string Baconian_Cipher::decipher(const string &text) {
    string result, text2;

    // Convert every (A or a) into 0 and every (B or b) into 1 and add this to text2
    for (char character: text) {
        if (character == 'A' || character == 'a') text2 += '0';
        else if (character == 'B' || character == 'b') text2 += '1';
    }

    // Check about the existence of these unknown strings and ignore it
    deque<int> numbers;
    for (int i = 0; i < int(text2.size()); i++) {
        if ((text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '1' &&
             text2[i + 4] == '1') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '1' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '0' &&
             text2[i + 4] == '1') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '1' && text2[i + 3] == '0' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '0' && text2[i + 3] == '1' &&
             text2[i + 4] == '0') ||
            (text2[i] == '1' && text2[i + 1] == '1' && text2[i + 2] == '0' && text2[i + 3] == '1' &&
             text2[i + 4] == '1')) {
            continue;
        }

            // Take every 5 characters in an index of a deque to evaluate it
        else if (((text2[i] == '1' || text2[i] == '0') && (text2[i + 1] == '1' || text2[i + 1] == '0') &&
                  (text2[i + 2] == '1' || text2[i + 2] == '0') && (text2[i + 3] == '1' || text2[i + 3] == '0') &&
                  (text2[i + 4] == '1' || text2[i + 4] == '0'))) {
            int digit = 0;
            bitset<5> decimal(text2.substr(i, 5));
            digit = decimal.to_ulong();
            numbers.push_back(digit);
            i += 4;
        } else continue;
    }

    // Check if every index in the deque has a value and add it to the result
    for (int number: numbers) {
        for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++) {
            if (number == (i - 65)) {
                result += static_cast<char>(i);
            }
        }
    }
    return result;
}

#endif
