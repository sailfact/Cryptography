# Makefile for Cryptography Assignment2
# Rsa Public key system
# Author : Ross Curley
# stdID : 19098081
CC=g++
CFLAGS=
OBJECTS=Main.o RSA.o IO.o
EXEC=rsa

$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

Main.o : Main.cpp RSA.h IO.h
	$(CC) -c Main.cpp $(CFLAGS)

Affine.o : RSA.cpp RSA.h 
	$(CC) -c RSA.cpp $(CFLAGS)

IO.o : IO.cpp IO.h
	$(CC) -c IO.cpp $(CFLAGS)

clean :
	rm -f $(EXEC) $(EXEC).exe $(OBJECTS) encrypt.txt decrypt.txt
