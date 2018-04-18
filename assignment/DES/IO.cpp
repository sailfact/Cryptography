#include "IO.h"

string readFile()
{
    ifstream ifs;
    string text;
    char c;
    ifs.open("infile.txt");
    if (ifs)
    {
        while (ifs.get(c))
        {
            text += c;
        }
    }
    else
    {
        cerr << "Unable to open file" << '\n';
    }
    ifs.close();
    return text;
}

void writeFile(string text, string file)
{
    ofstream ofs;
    ofs.open("outfile.txt");
    if (ofs.is_open())
    {
        ofs << text;
        ofs.close();
    }
    else
    {
        cout << "unable to open file" << file <<endl;
    }
}
