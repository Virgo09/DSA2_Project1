#ifndef CHAINEDHASHTABLE_HPP
#define CHAINEDHASHTABLE_HPP
#include <iostream>
#include <fstream>
#include "User.hpp"
   
class ChainedHashTable{
   
   public:
   ChainedHashTable();
   void readFile();
   void insertUser(std::string username, std::string password, int hashValue);
   int hash(std::string username);
   User* search(std::string userName);
   int longestBucket();
   
   private:
   static const int NUM_BUCKETS = 300;
   User* table[NUM_BUCKETS];

   };
   #endif