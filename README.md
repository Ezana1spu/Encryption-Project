# Encryption-Project
Starting with Main.cpp

## Simple Bitwise XOR Encryption/Decryption Program
This C++ program performs simple bitwise XOR encryption and decryption of text using a provided key. The program takes plaintext and a key as input, converts them to binary representations, performs bitwise XOR operation between the binary plaintext and the binary key, and displays the resulting ciphertext in both binary and ASCII formats.

## Features
Converts ASCII plaintext to binary representation
Converts ASCII key to binary representation
Performs bitwise XOR operation between binary plaintext and binary key to generate ciphertext
Converts binary ciphertext to ASCII representation
Decrypts the ciphertext using the same key and displays the decrypted plaintext in both binary and ASCII formats

## Functions

asciiToBinary(const string& input): Converts an ASCII string to its binary representation by iterating over each character and converting it to an 8-bit binary string using std::bitset.
binaryToAscii(const string& binary): Converts a binary string to its ASCII representation by iterating over the binary string in 8-bit chunks, converting each chunk to its corresponding character using std::bitset, and appending it to the ASCII string.
bitwiseXOR(const string& binaryPlaintext, const string& binaryKey): Performs bitwise XOR operation between the binary plaintext and the binary key. The key is repeated as needed to match the length of the plaintext. The operation is performed by iterating over the binary strings and applying the XOR operation between corresponding bits.

## Usage

Compile the program using a C++ compiler.
Run the compiled executable.
Enter the plaintext when prompted.
Enter the key when prompted.

The program will display the following outputs:
Ciphertext (binary): The binary representation of the ciphertext.
Ciphertext (ASCII): The ASCII representation of the ciphertext.
Decrypted Plaintext (binary): The binary representation of the decrypted plaintext.
Decrypted Plaintext (ASCII): The ASCII representation of the decrypted plaintext.



Now Main2.cpp
# Simple AES File Encryption/Decryption Program
This C++ program implements a simple file encryption and decryption algorithm based on the Caesar cipher technique. The program takes a key value, an operation mode (encryption or decryption), and a file name as input. It then performs the specified operation on the input file and generates a new output file containing the encrypted or decrypted data.

Features
Encrypts or decrypts a file using a Caesar cipher-like algorithm.
Supports alphabetic characters (both uppercase and lowercase).
Non-alphabetic characters are left unchanged.
Handles character wrapping (e.g., 'z' + 1 becomes 'a').

## Functions
findI(char ch): Returns the index of the given character ch in the alphabet arrays (abc and ABC). If the character is not found, it returns "NULL".
CheckIndex(int newI): Checks if the given index newI is within the bounds of the alphabet arrays (0-25) and performs wrapping if necessary.
encrypt(const string& input, const string& output, const int& key): Encrypts the contents of the input file using the provided key and generates an encrypted output file.
decrypt(const string& input, const string& output, const int& key): Decrypts the contents of the input file using the provided key and generates a decrypted output file.

## Usage

Compile the program using a C++ compiler.
Run the compiled executable with the following command-line arguments:
Copy codeMain.exe <Key> <D/E> <File_name>

<Key>: An integer value representing the encryption/decryption key.
<D/E>: A single character indicating the operation mode ('D' for decryption, 'E' for encryption).
<File_name>: The name of the input file to be processed.

When prompted, enter the desired output file name for the encrypted or decrypted file.
The program will perform the specified operation and generate the output file with the encrypted or decrypted data.
A success message will be displayed upon completion.