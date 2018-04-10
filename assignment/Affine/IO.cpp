#include "IO.h"

IO::IO(string inFile, string outFile)
{
    this->inFile = inFile;
    this->outFile = outFile;
}

string IO::readFile()
{
    ifstream ifs;
    ifs.open(inFile);
    string text((istreambuf_iterator<char>(ifs)),
                 istreambuf_iterator<char>());

    ifs.close();
    return text;   
}

void IO::writeFile(string text)
{
    ofstream ofs;
    ofs.open(outFile, std::ofstream::out);
    if (ofs)
    {
        ofs << text;
    }
    ofs.close();
}