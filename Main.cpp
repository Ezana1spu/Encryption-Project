#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

//Function to convert ASCII plaintext to binary text
string asciiToBinary(const string& input){
    string binary;
    for (char ch : input){
        binary += bitset<8>(ch).to_string();
    }
    return binary;
}

//Function to convert binary ciphertext to ASCII ciphertext
string binaryToAscii(const string& binary){
    string ascii;
    for (size_t i = 0; i < binary.length(); i += 8){
        string byte = binary.substr(i, 8);
        char ch = static_cast<char>(bitset<8>(byte).to_ulong());
        ascii += ch;
    }
    return ascii;
}

//Function to perform bitwise XOR between plaintext and binary key
string bitwiseXOR(const string& binaryPlaintext, const string& binaryKey){
    string result;
    for (size_t i = 0; i < binaryPlaintext.length(); ++i){
        char ch1 = binaryPlaintext[i];
        char ch2 = binaryKey[i % binaryKey.length()];
        result += (ch1 == ch2) ? '0' : '1';
    }
    return result;
}
int main() {
    string plaintext, binaryPlaintext, key, binaryKey, binaryCiphertext, ciphertext;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    getline(cin, key);

    //Convert ASCII plaintext to binary
    binaryPlaintext = asciiToBinary(plaintext);

    //Convert ASCII key to binary
    binaryKey = asciiToBinary(key);

    //Perform XOR between binary plaintext and binary key
    binaryCiphertext = bitwiseXOR(binaryPlaintext, binaryKey);

    //Convert binary ciphertext to ASCII
    ciphertext = binaryToAscii(binaryCiphertext);

    cout << "Ciphertext (binary): " << binaryCiphertext << endl;
    cout << "Ciphertext (ASCII): " << ciphertext << endl;

    //Decryption
    string decryptedBinary = bitwiseXOR(binaryCiphertext, binaryKey);
    string decryptedPlaintext = binaryToAscii(decryptedBinary);

    cout << "Decrypted Plaintext (binary): " << decryptedBinary << endl;
    cout << "Decrypted Plaintext (ASCII): " << decryptedPlaintext << endl;

    return 0;
}
