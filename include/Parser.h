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
    Parser(std::vector<char> charseq,  std::string input);
    ~Parser() = default;

    std::map<char, int> parse();
    
    // These methods allow changing the ruleset on the fly
    void setChars(std::vector<char> charseq);
    void setSequence(std::string seq);
    void appendSequence(std::string seq);
};

#endif

