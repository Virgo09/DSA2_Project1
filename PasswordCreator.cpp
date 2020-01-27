#include "PasswordCreator.hpp"

PasswordCreator::PasswordCreator(){}

void PasswordCreator::readFile(){
   std::fstream userNameFile;
   std::fstream raw;
   
   userNameFile.open("lastNames.txt");
   raw.open("raw.txt", std::ios::out);
   
   std::string ignore;
   
   if(!userNameFile.is_open()){
      std::cout << "Unable to open the username file." << std::endl;
   }
   if(!raw.is_open()){
      std::cout << "Unable to open the raw file." << std::endl;
   }
   while(getline(userNameFile, userID, ' ')){
      std::getline(userNameFile, ignore);
      userPassword = generatePassword();
      raw << userID + ' ' + userPassword + '\n';
   }
   raw.close();
   userNameFile.close();
}


bool PasswordCreator::usernameExists(std::string userID){
   
   std::string word;
   std::string ignore;
   std::fstream raw;
   raw.open("raw.txt");
   
   if(raw.is_open()){
      while(getline(raw, word, ' ')){
         std::getline(raw, ignore);
         if(word == userID) 
            return true;
      }
      return false;
   }
   return false;
}

std::string PasswordCreator::generatePassword(){
   std::string generatedPassword = "";
   
   for(int i = 0; i < 9; i++){
      generatedPassword += ('a' + rand() % 26);
   }
   return generatedPassword;
}