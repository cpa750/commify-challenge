#include "../include/Calculator.h"
#include <vector>

Calculator::Calculator(Ruleset rs) // Must construct the base class first
{
    this->ruleset = rs;
    std::vector<char> items = rs.getItems();
    this->parser.setChars(items);
    // Now that the ruleset is in scope,
    // set the characters for the parser
}

void Calculator::addItems(std::string itemSequence)
{
    this->parser.appendSequence(itemSequence);
}

void Calculator::applySpecials()
{
    // This algorithm gets the (best) special
    // if it exists, gets the difference between
    // the subtotal and the total with the special applied,
    // and subtracts that difference from the subtotal
    for (auto i : parser.getChars())
    {
        std::vector<std::vector<int>> specials = this->ruleset.getSpecials(i);
        if (specials.size() < 1) return; // Don't try to apply specials that don't exist
        else if (specials.size() == 1)
        {
            int totalDiff = this->total - 
            (this->parseResults.at(i) / specials[0][0]) * specials[0][1];
            this->total -= totalDiff;
        }
        else
        {
            int totalDiff = this->total - getBestSpecial(i, specials);
            this->total -= totalDiff;
        }
        // Could just do if...else but keeping it like this
        // avoids unneccessary calls to getBestSpecial
    }
}

void Calculator::calculateSubtotal()
{
    this->total = 0;
    for (auto i: parser.getChars())
    {
        this->total += this->parseResults.at(i) * this->ruleset.getUnitPrice(i);
    }
}

int Calculator::getBestSpecial(char item, std::vector<std::vector<int>> specials)
{
    // Getting the best special using a cost-minimising
    // algorithm for the consumer
    int lowestTotal = this->total;
    for (auto i: specials)
    {
        int itemsOriginalPrice = this->ruleset.getUnitPrice(item) * this->parseResults.at(item);
        int specialPrice =
            (this->parseResults.at(item) / i[0]) * i[1] +
            (this->parseResults.at(item) % i[0]) * this->ruleset.getUnitPrice(item);

        int itemsDiff = itemsOriginalPrice - specialPrice;
        int totalAfterSpecial = this->total - itemsDiff;

        if (totalAfterSpecial < lowestTotal)
            lowestTotal = totalAfterSpecial;
            // Must compare the totals after the special deal
            // has been applied, not just the special deals
            // themselves.
    }
    return lowestTotal;
}

int Calculator::calculateTotal()
{
    this->parseResults = parser.parse();
    this->calculateSubtotal();
    this->applySpecials();
    return this->total;
}

