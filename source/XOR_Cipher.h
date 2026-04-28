#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- XOR_Cipher class
class XOR_Cipher {
public:
    void run();

    int cipher(const string &text);

    string decipher(const string &text);
};

// ---------------------------------------- run
void XOR_Cipher::run() {
    cout << "# ===== Welcome to XOR Cipher ===== #" << endl;
    string text, text1, key, key1;
    int choice;
    bool firstCheck = true;

    while (firstCheck) {
        string menu9 = "What do you want to do?\n [1] Encryption Text.\n [2] Decryption Text.\n [3] Exit This Cipher.\nEnter Your Choice : ", res = "";
        vector<string> choices = {"1", "2", "3"};
        choice = menu_check(choices, menu9);

        if (choice == 1) {
            cout << "Enter the text you want to encrypt :";
            getline(cin, text);
            for (char character: text) {
                if (!isspace(character)) text1 += character;
            }
            text = text1;

            while (true) {
                bool alpha = false;
                cout << "Enter the key for Encryption (Only Letters) : ";
                getline(cin, key);
                for (char i: key) {
                    if (!isalpha(i)) {
                        alpha = true;
                        break;
                    }
                }

                if (!alpha) break;
                else cout << "Please enter a valid key." << endl;
            }

            for (int i = 0; i < ceil(double(text.length() / key.length())); i++)
                key1 += key;

            for (int i = 0; i < int(text.length()); i++) {
                res += char(key1[i] ^ text[i]);
            }

            vector<string> result;
            for (char i: res) {
                string sum = decipher(to_string(int(i)));
                result.push_back(sum);
            }

            cout << "The cipher of your text : " << res << endl;
            cout << "The Hexa Cipher : ";
            for (const string &i: result)
                cout << i << ' ';
            cout << endl << endl;
        } else if (choice == 2) {
            vector<string> arr;

            while (true) {
                bool check = false;
                cout
                        << "Enter the text you want to decrypt by hexa (composed of 2 digit hexadecimal separated by space):";
                getline(cin, text);
                for (char character: text) {
                    if (!isspace(character) && !isdigit(character) && toupper(character) != 'A' &&
                        toupper(character) != 'B' && toupper(character) != 'C' && toupper(character) != 'D' &&
                        toupper(character) != 'E' && toupper(character) != 'F') {
                        check = true;
                        break;
                    }
                }

                if (check) {
                    cout << "Please enter a valid hexadecimal number." << endl;
                    continue;
                }
                cin.ignore(0, '\n');

                string str;
                for (int i = 0; i < int(text.length()); i++) {
                    if (isspace(text[i]) && !isspace(text[i - 1])) {
                        arr.push_back(str);
                        str.clear();
                        continue;
                    } else if (isspace(text[i]) && isspace(text[i - 1]))
                        continue;
                    str += text[i];
                }
                arr.push_back(str);

                bool check1 = true;
                for (const string &i: arr) {
                    if (i.length() > 2) {
                        check1 = false;
                        break;
                    }
                }

                if (check1) break;
                cout << "Please enter a valid hexadecimal composed of 2 digits" << endl;
                arr.clear();
            }

            while (true) {
                bool alpha = false;
                cout << "Enter the key for decryption (only letters) : ";
                getline(cin, key);
                for (char character: key) {
                    if (!isalpha(character)) {
                        alpha = true;
                        break;
                    }
                }

                if (!alpha) break;
                else cout << "Please enter a valid key." << endl;
            }

            for (int i = 0; i < ceil(double(text.size() / key.size())); i++)
                key1 += key;

            for (int i = 0; i < int(arr.size()); i++) {
                res += char(key1[i] ^ char(cipher(arr[i])));
            }

            cout << "The Original Message is: " << res << endl << endl;
        } else return;

        firstCheck = continue_or();
    }
}

// ---------------------------------------- cipher
int XOR_Cipher::cipher(const string &text) {
    int sum = 0;

    for (char ch: text) {
        sum *= 16; // Shift left by multiplying by 16

        if (isdigit(ch)) sum += ch - '0';
        else sum += toupper(ch) - 'A' + 10; // Convert 'A'-'F' to 10-15
    }

    return sum;
}

// ---------------------------------------- decipher
string XOR_Cipher::decipher(const string &text) {
    int num = stoi(text);
    if (num == 0) return "0";

    string result;
    const string hex_chars = "0123456789ABCDEF";

    while (num > 0) {
        result = hex_chars[num % 16] + result; // Directly index into the lookup string
        num /= 16;
    }

    return result;
}

#endif
