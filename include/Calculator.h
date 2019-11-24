#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/Ruleset.h"

class Calculator
{
private:
    std::vector<char> items;
    std::map<char, int> parseResults;
    Ruleset ruleset;
    std::string sequence;
    int total;
    
    void applySpecials();
    void calculateSubtotal();
    int getBestSpecial(char item,
            std::vector<std::vector<int>> specials);

public:
    Calculator(Ruleset rs, std::string seq="");

    void addItems(std::string itemSequence);
    int calculateTotal();
    std::vector<char> getItems() { return this->items; }
    std::map<char, int> parse();

};

#endif

