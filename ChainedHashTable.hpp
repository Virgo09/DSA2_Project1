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
   ~ChainedHashTable();
   void readFile();
   void insertUser(User* user);
   int hash(std::string username);
   User* search(std::string userName);
   int longestBucket();
                           
                           private:
   static const int NUM_BUCKETS = 400;
   User* table[NUM_BUCKETS];

                           };
           #endif
