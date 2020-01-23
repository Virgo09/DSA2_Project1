/***************************************************************
Student Name:Justin Wymore
File Name: PasswordCreator.hpp
Assignment number: Project 1
Last edit: 23 January 2020

Creates a random 9-character password in all lowercase characters
and writes them to a file with their respective username
***************************************************************/

#ifndef PASSWORDCREATOR_HPP
#define PASSWORDCREATOR_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class PasswordCreator{

public:
   void readFile();
   std::string generatePassword(std::string userID);
   PasswordCreator();
   bool usernameExists(std::string userID);
private:
   std::string userID;
   std::string userPassword;

};

#endif
