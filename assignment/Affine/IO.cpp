#include "IO.h"

string readFile(const char *infile)
{
    ifstream ifs;
    string text;
    char c;
    ifs.open(infile);
    if (ifs)
    {
        while (ifs.get(c))
        {
            text += c;
        }
    }
    else
    {
        cerr << "Unable to open file" << infile << endl;
    }
    ifs.close();
    return text;
}

void writeFile(string text, const char *outfile)
{
    ofstream ofs;
    ofs.open(outfile);
    if (ofs.is_open())
    {
        ofs << text;
        ofs.close();
    }
    else
    {
        cerr << "unable to open file" << outfile << endl;
    }
}
