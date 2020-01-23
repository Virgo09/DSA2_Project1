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
      hashValue = hash(username);
      insertUser(username, password, hashValue);
   }
}
   
void ChainedHashTable::insertUser(std::string username, std::string password, int hashValue){
   if(table[hashValue] == nullptr){
      table[hashValue] = new User(username, password);
   }
   else{
      User* user = table[hashValue];
      while(user -> GetNext() != nullptr){
         user = user -> GetNext();
         if(user -> GetNext() == nullptr){
            user -> SetNext(new User(username, password));
         }
      }
   }
}
   
int ChainedHashTable::hash(std::string username){
   int hashValue;
   for(int i = 0; i < username.length(); i++){
      hashValue += username[i];
   }
   hashValue %= NUM_BUCKETS;
   return hashValue;
}

User* ChainedHashTable::search(std::string userName){
   int hashValue = hash(userName);
   std::cout << hashValue << std::endl;
   User* user = table[hashValue];
   if(table[hashValue] == nullptr){
      return nullptr;
   }
   else{
      while(user -> GetUsername() != userName){
         if(user -> GetUsername() == userName){
            return user;
         }
         else if(user == nullptr){
            return nullptr;
         }
         user = user -> GetNext(); 
      }
   }
   return nullptr;
}
   
int ChainedHashTable::longestBucket(){
   int count;
   int longest;
   User* user;
   for(int i = 0; i < NUM_BUCKETS; i++){
      user = table[i];
      while(user != nullptr){
         user = user -> GetNext();
         count++;
      }
      if(count > longest){
         longest = count;
      }
   }
   return longest;
}