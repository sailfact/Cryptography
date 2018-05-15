#ifndef IO_H
#define IO_H
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

std::string readFile(const char *);
void writeFile(std::string, const char *);
#endif