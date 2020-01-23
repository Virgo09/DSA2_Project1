/***************************************************************
Student Name:Justin Wymore
File Name: EncryptPasswords.hpp
Assignment number: Project 1
Last edit: 23 January 2020

Takes the passwords in the raw file and encrypts them 
with the vigenere cypher into a new file
***************************************************************/

#ifndef ENCRYPTPASSWORDS_HPP
#define ENCRYPTPASSWORDS_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

class EncryptPasswords{

    public:
   void SetKey(std::string key);
   void readFile();
   std::string encryptPassword(std::string userPassword);
   void writeToFile(std::string userID, 
                      std::string encryptedUserPassword);
   bool confirmChange(std::string userID);
                        
    private:
   std::string userPassword;
   std::string userID;
   std::string encryptedUserPassword;
   std::string key = "jones";
    };

#endif