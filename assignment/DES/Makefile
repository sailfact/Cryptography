# Makefile for cryptography assignment
SHELL = /bin/sh

OBJS = Main.o DES.o IO.o KeyGen.o
CFLAGS = -Wall -c
CC = g++

DES:${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
	-rm -f *.o 

.cpp.o:
	${CC} ${CFLAGS} -c $<