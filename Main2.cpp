#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string findI(char ch){
   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   for(int i = 0; i < 26; i++){
      if(ch == abc[i]){
         return to_string(i); 
      }
   }
   for(int i = 0; i < 26; i++){
      if(ch == ABC[i]){
         return to_string(i); 
      }
   }
   return "NULL";
}

int CheckIndex(int newI){
   if(newI > 25){
      return (newI % 25)-1;
   }else if(newI<0){
      return (25 +(newI % 25)) +1;
   }

   return newI;
}

//Function to encrypt data using AES
void encrypt(const string& input, const string& output, const int& key){
   ifstream inputFile(input, ios::binary);
   ofstream outputFile(output, ios::binary);

   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   //Encrypt the data
   char ch;
   while (inputFile.get(ch)){
      string foo = findI(ch);//Find index number
      if(foo == "NULL"){
         outputFile.put(ch); // if char NOT in abc/ABC array 
      }else{
         //cout << "foo: " << foo;
         int fooo = CheckIndex(stoi(foo) + key); //Check in bounds
         //cout << " fooo: " << fooo << endl;
         outputFile.put(abc[fooo]); //
      }
   }

   inputFile.close();
   outputFile.close();
}

//Function to decrypt the data using AES
// Opens input and output files in binary mode
// Iterates over each character in the input file
// For alphabetic characters, shifts them back by the given key value
// Writes the decrypted characters to the output file
void decrypt(const string& input, const string& output, const int& key){
   ifstream inputFile(input, ios::binary);
   ofstream outputFile(output, ios::binary);

   char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

   //Encrypt the data
   char ch;
   while (inputFile.get(ch)){
      string foo = findI(ch);//return index
      if(foo == "NULL"){
         outputFile.put(ch);
      }else{
         int fooo = CheckIndex(stoi(foo) - key); //Check in bounds
         outputFile.put(abc[fooo]); //
      }
   }

   inputFile.close();
   outputFile.close();
}


//comand line: Main.C <Key> <D/E> <File_name>
//c++ -o Main Main.cpp 
int main(int argc, char* argv[]) {
   int key = stoi(argv[1]);
   string inputFileName = argv[3];
   string encryptedFileName; 
   string decryptedFileName;

   if (*argv[2] == 'E') {

      cout << "Enter output file name for encryption: ";
      getline(cin, encryptedFileName);

      encrypt(inputFileName, encryptedFileName, key);
      cout << "File encrypted successfully!" << endl;

   }else{

      cout << "Enter output file name for decryption: ";
      getline(cin, decryptedFileName);

      decrypt(inputFileName, decryptedFileName, key);
      cout << "File decrypted successfully!" << endl;
   }
   return 0;
} 
