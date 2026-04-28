cmake_minimum_required(VERSION 3.27)
project(Encryption_and_Decryption_Application)

set(CMAKE_CXX_STANDARD 14)

add_executable(Encryption_and_Decryption_Application
        source/Affine_Cipher.h
        source/Atbash_Cipher.h
        source/Baconian_Cipher.h
        source/Morse_Cipher.h
        source/Polybius_Square_Cipher.h
        source/Rail-Fence_Cipher.h
        source/Route_Cipher.h
        source/Simple_Substitution_Cipher.h
        source/Vigenere_Cipher.h
        source/XOR_Cipher.h
        main.cpp
        source/Affine_Cipher.h)
