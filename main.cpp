/*
--> Author 1: Mohammed Atef Abd EL-Kader.
    --> ID: 20231143        --> Email: mohamed45452020@gmail.com
    --> Ciphers: Route Cipher, Vignere Cipher, Polybius Square Cipher and Morse Cipher.

--> Author 2: Esraa Emary Abd El-Salam.
    --> ID: 20230054        --> Email: esraaemary33@gmail.com
    --> Ciphers: Atbash Cipher, Baconoian Cipher, Simple Substitution Cipher and Morse Decipher.

--> Author 3: Aly El-Deen Yasser Aly.
    --> ID: 20230054        --> Email: aibakgaming747@gmail.com
    --> Ciphers: Affine Cipher, XOR Cipher and Rail Fence Cipher.

--> Purpose: this program is for encryption and decription your important information like your password, ID, etc.
======================================================================================================================*/

#include <bits/stdc++.h>

using namespace std;

#include "source/Affine_Cipher.h"
#include "source/Route_Cipher.h"
#include "source/Atbash_Cipher.h"
#include "source/Vigenere_Cipher.h"
#include "source/Baconian_Cipher.h"
#include "source/Simple_Substitution_Cipher.h"
#include "source/Polybius_Square_Cipher.h"
#include "source/Morse_Cipher.h"
#include "source/XOR_Cipher.h"
#include "source/Rail-Fence_Cipher.h"

// ================================================>> Main Program <<================================================ //
int main() {
    int option;
    string option1;

    // A description for user to simplify the program.
    cout << "# The Description For User To Simplify The Program:\n--> This program is for encryption your important "
            "information like password to be hard for strangers to get it.\n";
    cout << "--> Also it can decryption if your password is already encrypt with one of this ciphers.\n";
    cout << "// =================================================================================================== //";
    cout << "\n# ===== Welcome To Encryption and Decryption Program ===== #\n\n";

    // To keep the program running till user wants to exit.
    while (true) {
        // Show the available ciphers for user.
        string menu11 = "Which type of Cipher do you want?\n [1] Affine Cipher.\n [2] Route Cipher."
                        "\n [3] Atbash Cipher.\n [4] Vignere Cipher.\n [5] Baconian Cipher."
                        "\n [6] Simple Substitution Cipher.\n [7] Polybius Square Cipher."
                        "\n [8] Morse Cipher.\n [9] XOR Cipher.\n [10] Rail-Fence Cipher."
                        "\n [11] Exit Program.\nEnter Your Choice : ";
        vector<string> choices = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
        option = menu_check(choices, menu11);

        // Affine Cipher.
        if (option == 1) {
            Affine_Cipher system;
            system.run();
        }

            // Route Cipher.
        else if (option == 2) {
            Route_Cipher system;
            system.run();
        }

            // Atbash Cipher.
        else if (option == 3) {
            Atbash_Cipher system;
            system.run();
        }

            // Vignere Cipher.
        else if (option == 4) {
            Vigenere_Cipher system;
            system.run();
        }

            // Baconoian Cipher.
        else if (option == 5) {
            Baconian_Cipher system;
            system.run();
        }

            // Simple Substitution Cipher.
        else if (option == 6) {
            Simple_Substitution_Cipher system;
            system.run();
        }

            // Polybius Square Cipher.
        else if (option == 7) {
            Polybius_Square_Cipher system;
            system.run();
        }

            // Morse Cipher.
        else if (option == 8) {
            Morse_Cipher system;
            system.run();
        }

            // XOR Cipher.
        else if (option == 9) {
            XOR_Cipher system;
            system.run();
        }

            // Rail-Fence Cipher.
        else if (option == 10) {
            RailFence_Cipher system;
            system.run();
        }

            // Exit Program.
        else if (option == 11) {
            cout << "===> Thanks For Using Our Program..." << endl;
            cout << "===> See You Later..." << endl;
            break;
        }
    }
}
