#ifndef _IO_H
#define _IO_H
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

using namespace std;
class IO
{
    public:
        IO(string inFile, string outFile);
        string readFile();
        void writeFile(string text);
    private:
        string inFile;
        string outFile;


};
#endif
