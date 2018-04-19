#include "IO.h"
///
/// readFile
/// takes a filename and reads it char by char
/// into a string that is reaturned
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
///
/// writeFile
/// takes a string and a filename and writes the
/// string to the file
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
