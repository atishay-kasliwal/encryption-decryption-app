#ifndef MORSE_CIPHER_H
#define MORSE_CIPHER_H

#include <bits/stdc++.h>

using namespace std;

// ---------------------------------------- Morse_Cipher class
class Morse_Cipher {
public:
    void run();

    void cipher(const string &text);

    void decipher(const string &text);
};

// ---------------------------------------- run
void Morse_Cipher::run() {
    int Choice;
    cout << "\n# ===== Welcome to Morse Cipher ===== #" << endl;
    bool check = true;
    while (check) {
        // Showing a list for user to choose encryption or decryption
        string menu7 = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\nEnter your choice : ";
        vector<string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu7);

        // If he chooses encryption
        if (Choice == 1) {
            string message;
            cin.ignore(0, '\n');

            // To get the text from the user and check the validity of it
            while (true) {
                int count = 0;
                cout << "Enter your text you want to encrypt: ";
                getline(cin, message);

                for (char character: message) {
                    if (!isalpha(character) && !isdigit(character) && !isspace(character)) {
                        cout << "Please enter a valid message." << endl;
                        break;
                    } else { count += 1; }
                }

                if (count == int(message.size())) { break; }
            }
            cipher(message);
            cout << endl;
        }

            // If a user chooses to decrypt
        else if (Choice == 2) {
            string message;
            cin.ignore(0, '\n');

            // To get the text from the user and check the validity of it
            while (true) {
                int count = 0;
                cout << "Enter your text you want to encrypt: ";
                getline(cin, message);

                for (char character: message) {
                    if (static_cast<int>(character) != 46 && static_cast<int>(character) != 45 && !isspace(character)) {
                        cout << "Please enter a valid message." << endl;
                        break;
                    } else { count += 1; }
                }

                if (count == int(message.size())) { break; }
            }
            decipher(message);
            cout << endl;
        } else return;

        // Exit of this cipher
        check = continue_or();
    }
}

// ---------------------------------------- cipher
void Morse_Cipher::cipher(const string &text) {
    string result;
    static const unordered_map<char, string> morse_map = {
            {'A', ".-"},
            {'B', "-..."},
            {'C', "-.-."},
            {'D', "-.."},
            {'E', "."},
            {'F', "..-."},
            {'G', "--."},
            {'H', "...."},
            {'I', ".."},
            {'J', ".---"},
            {'K', "-.-"},
            {'L', ".-.."},
            {'M', "--"},
            {'N', "-."},
            {'O', "---"},
            {'P', ".--."},
            {'Q', "--.-"},
            {'R', ".-."},
            {'S', "..."},
            {'T', "-"},
            {'U', "..-"},
            {'V', "...-"},
            {'W', ".--"},
            {'X', "-..-"},
            {'Y', "-.--"},
            {'Z', "--.."},
            {'1', ".----"},
            {'2', "..---"},
            {'3', "...--"},
            {'4', "....-"},
            {'5', "....."},
            {'6', "-...."},
            {'7', "--..."},
            {'8', "---.."},
            {'9', "----."},
            {'0', "-----"}
    };

    for (char ch: text) {
        ch = toupper(ch);
        if (morse_map.count(ch)) {
            result += morse_map.at(ch) + " ";
        } else if (isspace(ch)) {
            result += "  ";  // Double space for word separation
        }
    }

    cout << "The Original Message is: " << result << endl;
}

// ---------------------------------------- decipher
void Morse_Cipher::decipher(const string &text) {
    string result;
    deque<string> morse;
    deque<char> morse2;
    for (int i = '0'; i <= 'Z'; i++) {
        if (i == 'A') {
            morse.push_back(".-");
            morse2.push_back('A');
        } else if (i == 'B') {
            morse.push_back("-...");
            morse2.push_back('B');
        } else if (i == 'C') {
            morse.push_back("-.-.");
            morse2.push_back('C');
        } else if (i == 'D') {
            morse.push_back("-..");
            morse2.push_back('D');
        } else if (i == 'E') {
            morse.push_back(".");
            morse2.push_back('E');
        } else if (i == 'F') {
            morse.push_back("..-.");
            morse2.push_back('F');
        } else if (i == 'G') {
            morse.push_back("--.");
            morse2.push_back('G');
        } else if (i == 'H') {
            morse.push_back("....");
            morse2.push_back('H');
        } else if (i == 'I') {
            morse.push_back("..");
            morse2.push_back('I');
        } else if (i == 'J') {
            morse.push_back(".---");
            morse2.push_back('J');
        } else if (i == 'K') {
            morse.push_back("-.-");
            morse2.push_back('K');
        } else if (i == 'L') {
            morse.push_back(".-..");
            morse2.push_back('L');
        } else if (i == 'M') {
            morse.push_back("--");
            morse2.push_back('M');
        } else if (i == 'N') {
            morse.push_back("-.");
            morse2.push_back('N');
        } else if (i == 'O') {
            morse.push_back("---");
            morse2.push_back('O');
        } else if (i == 'P') {
            morse.push_back(".--.");
            morse2.push_back('P');
        } else if (i == 'Q') {
            morse.push_back("--.-");
            morse2.push_back('Q');
        } else if (i == 'R') {
            morse.push_back(".-.");
            morse2.push_back('R');
        } else if (i == 'S') {
            morse.push_back("...");
            morse2.push_back('S');
        } else if (i == 'T') {
            morse.push_back("-");
            morse2.push_back('T');
        } else if (i == 'U') {
            morse.push_back("..-");
            morse2.push_back('U');
        } else if (i == 'V') {
            morse.push_back("...-");
            morse2.push_back('V');
        } else if (i == 'W') {
            morse.push_back(".--");
            morse2.push_back('W');
        } else if (i == 'X') {
            morse.push_back("-..-");
            morse2.push_back('X');
        } else if (i == 'Y') {
            morse.push_back("-.--");
            morse2.push_back('Y');
        } else if (i == 'Z') {
            morse.push_back("--..");
            morse2.push_back('Z');
        } else if (i == '1') {
            morse.push_back(".----");
            morse2.push_back('1');
        } else if (i == '2') {
            morse.push_back("..---");
            morse2.push_back('2');
        } else if (i == '3') {
            morse.push_back("...--");
            morse2.push_back('3');
        } else if (i == '4') {
            morse.push_back("----.");
            morse2.push_back('4');
        } else if (i == '5') {
            morse.push_back(".....");
            morse2.push_back('5');
        } else if (i == '6') {
            morse.push_back("-....");
            morse2.push_back('6');
        } else if (i == '7') {
            morse.push_back("--...");
            morse2.push_back('7');
        } else if (i == '8') {
            morse.push_back("---..");
            morse2.push_back('8');
        } else if (i == '9') {
            morse.push_back("----.");
            morse2.push_back('9');
        } else if (i == '0') {
            morse.push_back("-----");
            morse2.push_back('0');
        }
    }

    deque<string> text1;
    string port;
    for (int i = 0; i < int(text.size()); i++) {
        if (i == int(text.size()) - 1) {
            port += text[i];
            text1.push_back(port);
            break;
        } else if (isspace(text[i]) && isspace(text[i + 1]) && isspace(text[i + 2])) {
            text1.push_back(port);
            text1.push_back(" ");
            port.clear();
            i += 2;
        } else if (isspace(text[i]) && isspace(text[i + 1])) {
            text1.push_back(port);
            port.clear();
            i += 1;
        } else if (isspace(text[i])) {
            text1.push_back(port);
            port.clear();
        } else port += text[i];
    }

    for (const auto &i: text1) {
        int count = 0;
        for (int j = 0; j < int(morse.size()); j++) {
            if (i == morse[j]) {
                result += morse2[j];
                count++;
            }
        }
        if (count == 0 && i == " ")
            result += " ";
    }
    cout << "The Decrypted Message is: " << result << endl;
}

#endif
