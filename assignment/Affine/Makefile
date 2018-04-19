# Makefile for Cryptography Assignment
# Affine Cipher
# Author : Ross Curley
# stdID : 19098081
CC=g++
CFLAGS=
OBJECTS=Main.o Affine.o IO.o
EXEC=Affine

$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

Main.o : Main.cpp Affine.h IO.h
	$(CC) -c Main.cpp $(CFLAGS)

Affine.o : Affine.cpp Affine.h IO.h
	$(CC) -c Affine.cpp $(CFLAGS)

IO.o : IO.cpp IO.h
	$(CC) -c IO.cpp $(CFLAGS)

clean :
	rm -f $(EXEC) $(EXEC).exe $(OBJECTS) encrypt.txt decrypt.txt
