#ifndef USER_HPP
#define USER_HPP
#include <string>

class User{

public:
   User();
   User(std::string userName, std::string password, User* next = nullptr);
   void SetNext(User* next);
   std::string GetUsername();
   std::string GetPassword();
   User* GetNext();

private:
   std::string userName;
   std::string password;
   User* next;
};

   #endif