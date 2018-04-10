#include "IO.h"

IO::IO(string inFile, string outFile)
{
    this->inFile = inFile;
    this->outFile = outFile;
}

string IO::readFile()
{
    ifstream ifs;
<<<<<<< HEAD
    ifs.open(inFile);
=======
    ifs.open(inFile, ios::in);
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
    string text((istreambuf_iterator<char>(ifs)),
                 istreambuf_iterator<char>());

    ifs.close();
    return text;
}

void IO::writeFile(string text)
{
    ofstream ofs;
<<<<<<< HEAD
    ofs.open(outFile, std::ofstream::out);
    if (ofs)
    {
        ofs << text;
    }
    ofs.close();
}
=======
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
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
