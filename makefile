# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -g -Wall

OBJECTS = ChainedHashTable.o EncryptPasswords.o PasswordCreator.o User.o
HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

testBuild: $(OBJECTS)
	$(CC) $(CFLAGS) -Itest/catch/catch.hpp -o test/passwordCreatorTest $(OBJECTS) test/passwordCreatorTest.cpp

test: clean testBuild
	test/passwordCreatorTest --success

clean:
	$(RM) *.o *.gch core main test/passwordCreatorTest
