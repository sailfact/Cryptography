#include "IO.h"

IO::IO(string inFile, string outFile)
{
    this->inFile = inFile;
    this->outFile = outFile;
}

string IO::readFile()
{
    ifstream ifs;
    ifs.open(inFile, ofstream::in);
    string text((istreambuf_iterator<char>(ifs)),
                 istreambuf_iterator<char>());

    ifs.close();
    return text;   
}

void IO::writeFile(string text)
{
    ofstream ofs;
    ofs.open(outFile, ofstream::out);
    ofs << text;
    ofs.close();
}