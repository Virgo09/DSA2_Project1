/***************************************************************
Student Name:Justin Wymore
File Name: ChainedHashTable.hpp
Assignment number: Project 1
Last edit: 23 January 2020

Reads in usernames and encrypted passwords 
and hashes their object into a table
***************************************************************/
#ifndef CHAINEDHASHTABLE_HPP
#define CHAINEDHASHTABLE_HPP
#include <iostream>
#include <fstream>
#include "User.hpp"
     
class ChainedHashTable{
         
         public:
   ChainedHashTable();
   void readFile();
   void insertUser(std::string username, 
                        std::string password, 
                        int hashValue);
   int hash(std::string username);
   User* search(std::string userName);
   int longestBucket();
         
         private:
   static const int NUM_BUCKETS = 300;
   User* table[NUM_BUCKETS];

         };
     #endif