#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <string>
#include <vector>

#include "exceptions.h"

class Parser
{
    private:
    std::vector<char> chars;
    std::string sequence;

public:
    Parser(std::vector<char> charseq={},  std::string input="");

    std::map<char, int> parse();
    
    void setChars(std::vector<char> charseq);
    void setSequence(std::string seq);
    void appendSequence(std::string seq);

    std::vector<char> getChars() { return this->chars; }
};

#endif

