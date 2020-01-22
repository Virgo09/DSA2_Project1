#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../PasswordCreator.cpp"
#include "../EncryptPasswords.cpp"

TEST_CASE("Checking that all names were read in")
{
   PasswordCreator obj;
   srand(time(NULL));
   
   obj.readFile();
   REQUIRE(obj.usernameExists("WYMORE"));    //verify my last name was included
   REQUIRE(obj.usernameExists("AALDERINK")); //verify last name in list was included
   REQUIRE(!obj.usernameExists("AAAAAAA"));  //verify the name does not exist
   
}

TEST_CASE("Confirm new passwords don't match previous"){
   EncryptPasswords obj;
   
   obj.readFile();
   REQUIRE(obj.confirmChange("WYMORE"));
   REQUIRE(obj.confirmChange("AALDERINK"));
}

// Compile & run:
// make clean test
