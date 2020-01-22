#include "EncryptPasswords.hpp"

void EncryptPasswords::readFile(){
   std::fstream rawFile;
   std::fstream encryptedFile;
   
   rawFile.open("raw.txt", std::ios::in);
   encryptedFile.open("encryptedData.txt", std::ios::out);
         
   if(!rawFile.is_open()){
      std::cout << "Unable to open the raw file." << std::endl;
   }
   
   while(getline(rawFile, userID, ' ')){
      std::getline(rawFile, userPassword, '\n');
      encryptedUserPassword = encryptPassword(userPassword);
      encryptedFile << userID + ' ' + encryptedUserPassword + '\n';
   }
   rawFile.close();
}

void EncryptPasswords::SetKey(std::string key) {
   this -> key = key;
}

std::string EncryptPasswords::encryptPassword(std::string userPassword){
   encryptedUserPassword = "";

   for (int i = 0, j = 0; i < 9; i++) {
      encryptedUserPassword += (userPassword[i] - 'a' + key[j] - 'a') % 26 + 'a'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
      j = (j + 1) % key.length();
   }
   return encryptedUserPassword;
}
   
bool EncryptPasswords::confirmChange(std::string userID){
   std::string userNameUnencrypted;     
   std::string userNameEncrypted;
   std::string unencryptedPassword;
   std::string encryptedPassword;
   std::fstream rawFile;
   std::fstream encryptedFile;
   
   rawFile.open("raw.txt", std::ios::in);
   encryptedFile.open("encryptedData.txt", std::ios::in);
   
   if(rawFile.is_open() && encryptedFile.is_open()){
      while(getline(rawFile, userNameUnencrypted, ' ') 
            && getline(encryptedFile, userNameEncrypted, ' ')){
         std::getline(rawFile, unencryptedPassword);
         std::getline(encryptedFile, encryptedPassword);
         if(encryptedPassword != unencryptedPassword) 
            return true;
      }
      std::cout << "106";
      return false;
   }
   std::cout << "109";
   return false;

}