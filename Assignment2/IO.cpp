#include "IO.h"

std::string readFile(const char *infile)
{
    ifstream ifs;
    std::string text;
    char c;
    ifs.open(infile);
    if (ifs)
    {
        while (ifs.get(c))
            text += c;
    }
    else
        std::cerr << "Unable to open file" << infile << std::endl;
    ifs.close();
    return text;
}

void writeFile(std::string text, const char *outfile)
{
    ofstream ofs;
    ofs.open(outfile);
    if (ofs.is_open())
    {
        ofs << text;
        ofs.close();
    }
    else
        std::cerr << "unable to open file" << outfile << std::endl;
}
