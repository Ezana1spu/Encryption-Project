#include <iostream>

#include <fstream>

#include <string>

#include <vector>



using namespace std;



//Key for AES encryption (128 bits)

const string
AES_KEY = "secretkey12345";



//Function to encrypt data using AES

void encryptAES(const
string& input, const
string& output, const
string& key){

   ifstream inputFile(input,
ios::binary);

   ofstream outputFile(output,
ios::binary);



   //Prepare the key

   string paddedKey = key;

   while(paddedKey.size() < 
16){

       paddedKey += ' ';
//Pad key with spaces if needed

   }



   //Use the key to perform encryption

   for(char
keyChar : paddedKey){

       outputFile.put(keyChar);

   }



   //Encrypt the data

   char ch;

   while (inputFile.get(ch)){

       outputFile.put(ch ^ paddedKey[0]);
//Simple XOR encryption

   }



   inputFile.close();

   outputFile.close();

}



//Function to decrypt the data using AES

void decryptAES(const
string& input, const
string& output, const
string& key){

   ifstream inputFile(input,
ios::binary);

   ofstream outputFile(output,
ios::binary);



   //Read the key from the encrypted file

   string encryptedKey;

   for(int
i = 0;
i < 16;
++i){

       char ch;

       inputFile.get(ch);

       encryptedKey +=
ch;

   }



   //Use the key to perform decryption

   string paddedKey = key;

   while (paddedKey.size() < 
16) {

       paddedKey += ' ';
//Pad key with space if needed

   }



   //Decrypt the data

   char ch;

   while(inputFile.get(ch)){

       outputFile.put(ch ^ paddedKey[0]);

   }



   inputFile.close();

   outputFile.close();

}



int main() {

   string inputFileName,
encryptedFileName,
decryptedFileName;



   cout <<
"Enter input file name: ";

   getline(cin,
inputFileName);

   cout <<
"Enter output file name for encryption: ";

   getline(cin,
encryptedFileName);



   encryptAES(inputFileName,
encryptedFileName,
AES_KEY);

   cout <<
"File encrypted successfully!" 
<< endl;



   cout <<
"Enter input file name for decryption: ";

   getline(cin,
encryptedFileName);

   cout <<
"Enter output file name for decryption: ";

   getline(cin,
decryptedFileName);



   decryptAES(encryptedFileName,
decryptedFileName,
AES_KEY);;

   cout <<
"File decrypted successfully!" 
<< endl;



   return 0;