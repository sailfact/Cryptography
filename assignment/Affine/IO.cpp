#include "IO.h"

IO::IO(string inFile, string outFile)
{
    this->inFile = inFile;
    this->outFile = outFile;
}

string IO::readFile()
{
    ifstream ifs;
    ifs.open(inFile, ios::in);
    string text((istreambuf_iterator<char>(ifs)),
                 istreambuf_iterator<char>());

    ifs.close();
    return text;
}

void IO::writeFile(string text)
{
    ofstream ofs;
    ofs.open(outFile, ios::out);
    if (ofs.is_open())
    {
        ofs << text;
        ofs.close();
    }
    else
    {
        cout << "unable to open file" << outFile <<endl;
    }
}
