#include "../include/Parser.h"
#include <utility>
#include <vector>

Parser::Parser(std::vector<char> charsequence,  std::string input)
{
    this->chars = charsequenc;
    this->sequence = input;
}

std::map<char, int> Parser::parse()
{
    if (this->chars.empty())
        throw CharListEmpty();
    else if (this->sequence.empty())
        throw StringEmpty();
    // Must check to make sure both the char list
    // and the string sequence are not empty

    std::map<char, int> ret;
    for (auto i : this->chars)
    {
        int count = 0;
        for (auto j : sequence)
        {
            if (j == i)
                ++count;
        }
        ret.insert(std::make_pair(i, count));
    }
    return ret;
}

