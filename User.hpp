/***************************************************************
Student Name:Justin Wymore
File Name: User.hpp
Assignment number: Project 1
Last edit: 23 January 2020

Creates user objects and singulary linked lists
***************************************************************/

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