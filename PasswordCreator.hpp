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
