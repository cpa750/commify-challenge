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
    Parser(std::vector<char> charsequence,  std::string input);
    ~Parser() = default;

    std::map<char, int> parse(); // TODO: write tests for this
};

#endif

