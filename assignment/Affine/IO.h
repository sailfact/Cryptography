#ifndef _IO_H
#define _IO_H
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
<<<<<<< HEAD
#define BUFSIZE 1024
=======
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c

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