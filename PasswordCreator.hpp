#ifndef PASSWORDCREATOR_HPP
#define PASSWORDCREATOR_HPP
#include <fstream>
#include <iostream>
#include <string>

class PasswordCreator{

public:
   void readFile();
   void generatePassword(std::string userID);
   void writeToFile(std::string userID, std::string userPassword);
   PasswordCreator();
   bool usernameExists(std::string userID);
private:
   std::string userID;
   std::string userPassword;

};

#endif
