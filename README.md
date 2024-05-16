# Encryption-Project
# XOR Encryption and Decryption
This repository contains a C++ program that demonstrates AES encryption and decryption using a Command Line Interface (CLI) with a simple menu.

# Features

-Encrypts plaintext using AES algorithm and a provided key

-Decrypts ciphertext using the same key

-Supports input from the user via CLI

-Converts plaintext to binary for encryption

-Converts ciphertext back to ASCII for decryption

-Performs bitwise XOR operation for encryption and decryption

# How to run program

Run and compile the code and when the prompt shows on the terminal enter the plaintext and the key

Once you enter the plaintext and the key you will get a retrun of the ciphertext in binary and ascii and the decrypted plaintext in binary and ascii

# Caesar Cipher Encryption and Decryption
This repository contains a C++ program that demonstrates Caesar cipher encryption and decryption using a Command Line Interface (CLI).

# Features

-Encrypts text files using a Caesar cipher with a provided key

-Decrypts text files using the same key

-Supports input from the user via CLI

-Handles both lowercase and uppercase letters

-Allows the user to specify the input file, output file for encryption, output file for decryption, and the encryption/decryption key via command line arguments

# How to run program

This program encrypts a txt file using Monoalphabetic substitution method. The program can be ran using the command line: ./Main2.C <Key> <D/E> <File_name>. 

-Key: should be an int that represents the shift in the alphabet 

-D/E: D is for decryption and E is for encryption. 

-File_name: text file that is being encrypted or decrypted

Once you have started the program through the command line it will ask you in the terminal where you want to output the encrypted or decrypted message to. If file doesn't exist it will make a new file to output to. 
