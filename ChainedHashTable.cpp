#include "ChainedHashTable.hpp"

ChainedHashTable::ChainedHashTable(){
   for(int i = 0; i < NUM_BUCKETS; i++){
      table[i] = nullptr;
   }
}

void ChainedHashTable::readFile(){
   std::string username;
   std::string password;
   User* user;
   int hashValue;
   std::fstream encryptedFile;
   encryptedFile.open("encryptedData.txt");
   
   while(std::getline(encryptedFile, username, ' ')){
      std::getline(encryptedFile, password);
      user = new User(username,password);
      insertUser(user);
   }
}
   
void ChainedHashTable::insertUser(User* user)
{
   int hashValue = hash(user -> GetUsername());
   user -> SetNext(table[hashValue]);
   table[hashValue] = user;
}
   
int ChainedHashTable::hash(std::string username){
   int hashValue = 0;
   for(int i = 0; i < username.length(); i++){
      hashValue += username[i];
   }
   hashValue %= NUM_BUCKETS;
   return hashValue;
}

User* ChainedHashTable::search(std::string userName){
   int hashValue = hash(userName);
   User* user = table[hashValue];
   
   while(user != nullptr){ 
      if(user -> GetUsername() == userName)
         return user;
      else 
         user = user -> GetNext(); 
   }

   return nullptr;
}
   
int ChainedHashTable::longestBucket(){
   int count = 0;
   int longest = 0;
   User* user;
   for(int i = 0; i < NUM_BUCKETS; i++){
      count = 0;
      user = table[i];
      while(user != nullptr){
         user = user -> GetNext();
         count++;
      }
      if(count > longest){
         longest = count;
         std::cout << i << std::endl;
      }
   }
   return longest;
}
