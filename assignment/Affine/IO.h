#ifndef _IO_H
#define _IO_H
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#define BUFSIZE 1024

using namespace std;
class IO {
    public:
        IO(string inFile, string outFile);
        string readFile();
        void writeFile(string text);
    private:
        string inFile;
        string outFile;


};
#endif