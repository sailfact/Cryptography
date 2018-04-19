/// IO.h
#ifndef _IO_H
#define _IO_H
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

using namespace std;

string readFile(const char *infile);
void writeFile(string text, const char *outfile);


#endif
