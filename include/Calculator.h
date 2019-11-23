#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/Parser.h"
#include "../include/Ruleset.h"

class Calculator : Parser
{
private:
    int total;
    Ruleset ruleset;
    std::map<char, int> parseResults;

    public:
    Calculator(Ruleset ruleset);

    void applySpecials();
    int getTotal();

};

#endif

