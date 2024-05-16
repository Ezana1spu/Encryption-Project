/*
This program encrypts a txt file using Monoalphabetic substitution method. The program can be ran using the command line: ./Main2.C <Key> <D/E> <File_name>. 
-Key: should be an int that represents the shift in the alphabet 
-D/E: D is for decryption and E iis for encryption. 
-File_name: text file that is being encrypted or decrypted

Once you have started the program through the command line it will ask you in the terminal where you want to output the encrypted or decrypted message to. If file doesn't exist it will make a new file to output to. 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/*
-Look in array of lowercase alphabets to check if ch is in it then returns index number or "NULL" if not found.
-Input: (char)ch-single character 
-Output: (string)-index number string or "Null" if not found
*/
string findI(char ch){
   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

   //look through array for matching char
   for(int i = 0; i < 26; i++){
      if(ch == abc[i]){
         return to_string(i); //convert index number to string
      }
   }
   return "NULL";
}


/*
-Look in array of uppercase alphabets to check if ch is in it then returns index number or "NULL" if not found.
-Input: (char)ch-single character 
-Output: (string)-index number string or "Null" if not found
*/
string findIUppercase(char ch){
   char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   //look through array for matching char
   for(int i = 0; i < 26; i++){
      if(ch == ABC[i]){
         return to_string(i); //convert index number to string
      }
   }
   return "NULL";
}


/*
-Check to see if idex number for char is in abc's range. If so set index value to the correct value. 
-Input: (int)newI-idex number 
-Output: (newI)-return new corrected index or original index if correction not needed. 
*/
int CheckIndex(int newI){
   if(newI > 25){
      return (newI % 25)-1;//positive index, start count from "a" and go forward
   }else if(newI<0){
      return (25 +(newI % 25)) +1;//negative index, start count from "z" and go backwards
   }
   return newI;
}


/*
-encrypt text file 
-Input: (string)input-input text file , (string)output-file print to, (int)key-encryption key
-Output: writes to file 
*/
void encrypt(const string& input, const string& output, const int& key){
   ifstream inputFile(input, ios::binary);
   ofstream outputFile(output, ios::binary);

   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   //Encrypt the data
   char ch;
   while (inputFile.get(ch)){
      string charIndex = findI(ch);
      if(charIndex == "NULL"){ //check if ch is lowercase 
         string charIndexUpper = findIUppercase(ch);
         if(charIndexUpper == "NULL"){ //check if ch is uppercase 
            outputFile.put(ch); //if char NOT in abc/ABC array 
         }else{ 
            int finalIndex = CheckIndex(stoi(charIndexUpper) + key); //Check in bounds
            outputFile.put(ABC[finalIndex]);
         }
      }else{
         int finalIndex = CheckIndex(stoi(charIndex) + key); //Check ch index in array
         outputFile.put(abc[finalIndex]);
      }
   }

   inputFile.close();
   outputFile.close();
}

<<<<<<< HEAD
//Function to decrypt the data using AES
// Opens input and output files in binary mode
// Iterates over each character in the input file
// For alphabetic characters, shifts them back by the given key value
// Writes the decrypted characters to the output file
=======

/*
-decrypt text file 
-Input: (string)input-input text file , (string)output-file print to, (int)key-decrypt key
-Output: writes to file 
*/
>>>>>>> 3ed3351c6ff3818a835622862445f315e6d1c717
void decrypt(const string& input, const string& output, const int& key){
   ifstream inputFile(input, ios::binary);
   ofstream outputFile(output, ios::binary);

   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
   
   //Encrypt the data
   char ch;
    while (inputFile.get(ch)){
      string charIndex = findI(ch);
      if(charIndex == "NULL"){ //check if ch is lowercase 
         string charIndexUpper = findIUppercase(ch);
         if(charIndexUpper == "NULL"){ //check if ch is uppercase 
            outputFile.put(ch); //if char NOT in abc/ABC array 
         }else{
            int finalIndex = CheckIndex(stoi(charIndexUpper) - key); //Check in bounds
            outputFile.put(ABC[finalIndex]); 
         }
      }else{
         int finalIndex = CheckIndex(stoi(charIndex) - key); //Check ch index in array
         outputFile.put(abc[finalIndex]); 
      }
   }

   inputFile.close();
   outputFile.close();
}


//command line: c++ -o Main Main.cpp, Main.C <Key> <D/E> <File_name>
int main(int argc, char* argv[]) {
   int key = stoi(argv[1]);
   string inputFileName = argv[3];
   string encryptedFileName; 
   string decryptedFileName;

   if (*argv[2] == 'E') { //encrypted

      cout << "Enter output file name for encryption: ";
      getline(cin, encryptedFileName);

      encrypt(inputFileName, encryptedFileName, key);
      cout << "File encrypted successfully!" << endl;

   }else{ //decrypted

      cout << "Enter output file name for decryption: ";
      getline(cin, decryptedFileName);

      decrypt(inputFileName, decryptedFileName, key);
      cout << "File decrypted successfully!" << endl;
   }
   return 0;
} 