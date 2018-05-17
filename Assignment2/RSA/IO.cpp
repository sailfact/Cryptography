/// IO.cpp
#include "IO.h"
/// readFile
/// Opens given files and returns file contents as a string

std::string readFile(const char *infile)
{
    std::ifstream ifs;
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
/// writeFile
/// writes given text to the given file
void writeFile(std::string text, const char *outfile)
{
    std::ofstream ofs;
    ofs.open(outfile);
    if (ofs.is_open())
    {
        ofs << text;
        ofs.close();
    }
    else
        std::cerr << "unable to open file" << outfile << std::endl;
}
