#include "PasswordCreator.hpp"

PasswordCreator::PasswordCreator(){}

void PasswordCreator::readFile(){
   std::fstream userNameFile;
   std::ofstream raw;
   userNameFile.open("lastNames.txt");
   raw.open("raw.txt");
   
   std::string ignore;
   
   if(userNameFile.is_open()){
      while(getline(userNameFile, userID, ' ')){
         std::getline(userNameFile, ignore);
         raw << userID + '\n';
      }
      raw.close();
      userNameFile.close();
   }
}

bool PasswordCreator::usernameExists(std::string userID){
   
   std::string word;
   
   std::fstream raw;
   raw.open("raw.txt");
   
   if(raw.is_open()){
      while(getline(raw, word)){
         if(word == userID) 
            return true;
      }
      return false;
   }
   return false;
}