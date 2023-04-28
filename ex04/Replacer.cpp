#include <iostream>
#include <fstream>
#include <sstream>

#include "Replacer.hpp"

Replacer::Replacer(std::string infile): _infile(infile)
{
    std::ifstream ifs(infile.c_str());
    if (ifs.fail())
        throw std::runtime_error("No such file: " + infile);
    std::string outfile(infile + ".replace"); 
    std::ifstream temp_fs(outfile.c_str());
    if (temp_fs.good())
    {
        std::cout << "\"" << outfile << "\" exits. Are you sure to replace it? [Y/n]" << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if (input != "Y" && input != "y")
            throw std::runtime_error("Abort to replace it!");
    }
    this->_outfile = outfile;
}

void Replacer::replace(std::string from, std::string to)
{
    if (from.empty())
        throw std::runtime_error("Empty string");
    std::ifstream ifs(this->_infile.c_str());
    std::ostringstream oss; oss << ifs.rdbuf();
    std::string origin = oss.str();
    std::ofstream ofs(this->_outfile.c_str());
    size_t next = origin.find(from);
    ofs << origin.substr(0, next);
    while (next != std::string::npos)    
    {
        ofs << to;
        size_t base = next + from.length();
        next = origin.find(from, base);
        ofs << origin.substr(base, next - base);
    }
}
