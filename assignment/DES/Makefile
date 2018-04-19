# Makefile for Cryptography Assignment
# DES Block Cipher
# Author : Ross Curley
# stdID : 19098081
CC=g++
CFLAGS=
OBJECTS=DES.o IO.o KeyGen.o Main.o
EXEC=Des

$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

Main.o: Main.cpp DES.h KeyGen.h IO.h
	$(CC) -c Main.cpp

DES.o: DES.h KeyGen.h SBOX.h DES.cpp
	$(CC) -c DES.cpp

KeyGen.o: KeyGen.h KeyGen.cpp
	$(CC) -c KeyGen.cpp

IO.o: IO.h IO.cpp
	$(CC) -c IO.cpp

clean:
	rm -f $(EXEC) $(OBJECTS) encrypt.txt decrypt.txt
