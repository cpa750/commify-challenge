#include "../include/Calculator.h"

Calculator::Calculator(Ruleset ruleset) : Parser({}, "")
// Must construct the base class first
{
    std::vector<char> items = ruleset.getItems();
    this->setChars(items);
    // Now that the ruleset is in scope,
    // set the characters for the parser
}

void Calculator::applySpecials()
{
    this->parseResults = this->parse();
    for (auto i : this->getChars())
    {
        std::vector<std::vector<int>> specials = this->ruleset.getSpecials(i);
        if (specials.size() <= 1)
            this->total -= 
    }

}

