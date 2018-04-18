CC = g++
CFLAGS  = -g -Wall

default: des

des:  Main.o DES.o KeyGen.o IO.o
	$(CC) $(CFLAGS) -o des Main.o DES.o KeyGen.o IO.o

Main.o: Main.cpp DES.h KeyGen.h IO.h
	$(CC) $(CFLAGS) -c Main.cpp

DES.o:  DES.cpp KeyGen.h SBOX.h
	$(CC) $(CFLAGS) -c DES.cpp

KeyGen.o:  KeyGen.cpp KeyGen.h
	$(CC) $(CFLAGS) -c KeyGen.cpp

IO.o:  IO.cpp IO.h
	$(CC) $(CFLAGS) -c IO.cpp

clean:
	$(RM) cdes *.o *~ des
