#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../PasswordCreator.hpp"
#include "../EncryptPasswords.hpp"
#include "../User.hpp"
#include "../ChainedHashTable.hpp"

TEST_CASE("Checking that all names were read in")
{
   PasswordCreator obj;
   srand(time(NULL));
   
   obj.readFile();
   REQUIRE(obj.usernameExists("WYMORE"));    //verify my last name was included
   REQUIRE(obj.usernameExists("AALDERINK")); //verify last name in list was included
   REQUIRE(!obj.usernameExists("AAAAAAA"));  //verify the name does not exist
   
}

TEST_CASE("Confirm new passwords are encrypted"){
   EncryptPasswords obj;
   
   obj.readFile();
   REQUIRE(obj.confirmChange("WYMORE"));
   REQUIRE(obj.confirmChange("AALDERINK"));
   REQUIRE(obj.encryptPassword("dsatwofun") == "mgnxoxthr");
}

TEST_CASE("Confirm users object gets created properly"){

   User* me = new User("Wymore", "dsatwofun");
   REQUIRE(me -> GetUsername() == "Wymore");
   REQUIRE(me -> GetPassword() == "dsatwofun");
   User* instructor = new User("Coffey", "iamteacher");
   User* classmate = new User("Maples", "classmate");
   instructor -> SetNext(classmate);
   REQUIRE(instructor -> GetNext() -> GetUsername() == "Maples");
   REQUIRE(instructor -> GetNext() -> GetPassword() == "classmate");

}

TEST_CASE("Confirm hashing"){

   ChainedHashTable* obj = new ChainedHashTable();
   
   User* userObj = new User("WYMORE", "dsatwofun");
   
   obj -> readFile();
   std::cout << obj -> longestBucket() << std::endl;
   REQUIRE(obj -> search("WYMORE") -> GetUsername() == "WYMORE");
   REQUIRE(obj -> search("AAAAAAA") == nullptr);


}

// Compile & run:
// make clean test
