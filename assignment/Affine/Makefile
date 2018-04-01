# Makefile for Cryptography Assignment 
# Affine Cipher
# Author : Ross Curley
# stdID : 19098081
CC = g++
LD = g++
FLAGS = -g -Wall
RM = /bin/rm -f

COMPILE = $(CC) $(FLAGS) -CC
OBJ := $(filter-out main.o, $(patsubst %.cpp,%.o,$(wildcard *.cpp)))
EXEC = Affine

all: $(EXEC)

%.o:%.cpp
	$(COMPILE) $<

$(EXEC): main.o libaffine.a
	$(CC) $(CFLAGS) main.o libaffine.a -o $@

libusp.a: $(OBJ)
	ar crs libaffine.a $(OBJ)

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY : cleanall
cleanall:
	$(RM) *.o
	$(RM) $(EXEC)
	$(RM) libaffine.a
	