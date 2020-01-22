#include "User.hpp"

User::User(std::string userName, std::string password, User* next){
   this -> userName = userName;
   this -> password = password;
   SetNext(next);
}

void User::SetNext(User* next){
   if(next != nullptr)
      this -> next = next;
   else
      this -> next = nullptr;
}

std::string User::GetUsername(){
   return this -> userName;
}

std::string User::GetPassword(){
   return this -> password;
}

User* User::GetNext(){
   return this -> next;
}