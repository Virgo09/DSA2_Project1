 /***************************************************************
Student Name:Justin Wymore
File Name: main.cpp
Assignment number: Project 1
Last edit: 24 January 2020

Directs program. Outputs 5 users with correct password combinations 
and 5 with incorrect password combinations
***************************************************************/

#include "ChainedHashTable.hpp"
#include "PasswordCreator.hpp"
#include "EncryptPasswords.hpp"

int main(){
   std::string username, password;
   std::fstream raw;
   raw.open("raw.txt", std::ios::in);
   PasswordCreator obj_create;
   EncryptPasswords obj_encrypt;
   ChainedHashTable* obj_table = new ChainedHashTable();

   srand(time(NULL));
   
   obj_create.readFile();
   obj_encrypt.readFile();
   obj_table -> readFile();
   
   for(int i = 0; i < 5; i++){
      std::getline(raw, username, ' ');
      std::getline(raw, password);
      
      if(obj_table -> search(username) -> GetPassword() == obj_encrypt.encryptPassword(password))
      {
         std::cout << "Username: " << username << std::endl;
         std::cout << "Password: " << password << std::endl;
         std::cout << "Match!!" << std::endl << std::endl;
      } 
      else{
         std::cout << "Username: " << username << std::endl;
         std::cout << "Password: " << password << std::endl;
         std::cout << "No Match!!" << std::endl << std::endl;
      }
   }
   raw.close();
   raw.open("raw.txt");
   
   for(int i = 0; i < 5; i++){
      std::getline(raw, username, ' ');
      std::getline(raw, password);
      
      if(obj_table -> search(username) -> GetPassword() != obj_create.generatePassword()){
         std::cout << "Username: " << username << std::endl;
         std::cout << "Password: " << password << std::endl;
         std::cout << "No Match!!" << std::endl << std::endl;
      }
      else{
         std::cout << "Username: " << username << std::endl;
         std::cout << "Password: " << password << std::endl;
         std::cout << "Match!!" << std::endl << std::endl;
      }
      
   }
   raw.close();
   obj_table -> ~ChainedHashTable();
   return 0;
}
