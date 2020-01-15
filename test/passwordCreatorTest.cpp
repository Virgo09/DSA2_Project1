#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../PasswordCreator.hpp"

TEST_CASE("Checking that all names were read in")
{
   PasswordCreator obj;
   
   obj.readFile();
   REQUIRE(obj.usernameExists("WYMORE"));    //verify my last name was included
   REQUIRE(obj.usernameExists("AALDERINK")); //verify last name in list was included
   REQUIRE(!obj.usernameExists("AAAAAAA"));   //verify the name does not exist
	/*Dictionary wordList;

	REQUIRE(wordList.IsWord("AARDVARK")); // verify that we didn't skip the first word
	REQUIRE(wordList.IsWord("ZYMURGY")); // verify that the entire file got written by checking last word
	REQUIRE(!wordList.IsWord("ZZZZ"));
	REQUIRE(!wordList.IsWord("MARCUS")); // proper noun not in the list given
*/
}

// Compile & run:
// make clean test
