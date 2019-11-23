#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/Parser.h"
#include "../include/Ruleset.h"

class Calculator
{
private:
    int total;
    Parser parser;
    Ruleset ruleset;
    std::map<char, int> parseResults;
    
    void applySpecials();
    void calculateSubtotal();
    int getBestSpecial(char item,
            std::vector<std::vector<int>> specials);

public:
    Calculator(Ruleset rs);

    void addItems(std::string itemSequence);
    int calculateTotal();

};

#endif

