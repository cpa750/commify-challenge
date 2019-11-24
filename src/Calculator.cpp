#include "../include/Calculator.h"
#include <vector>

Calculator::Calculator(Ruleset rs, std::string seq)
{
    this->ruleset = rs;
    this->items = rs.getItems();
    this->sequence = seq;
}

void Calculator::addItems(std::string itemSequence)
{
    for (auto i: itemSequence)
    {
        if (!this->ruleset.contains(i))
                throw std::out_of_range("Character or sequence not in ruleset");
    }
    this->sequence += itemSequence;
}

void Calculator::applySpecials()
{
    // This algorithm gets the (best) special
    // if it exists, gets the difference between
    // the subtotal and the total with the special applied,
    // and subtracts that difference from the subtotal
    for (auto i : this->getItems())
    {
        std::vector<std::vector<int>> specials = this->ruleset.getSpecials(i);
        if (specials.size() < 1) return; // Don't try to apply specials that don't exist
        else if (specials.size() == 1)
        {
            int itemsOriginalPrice =
                    this->ruleset.getUnitPrice(i) * this->parseResults.at(i);
            // Need to know item original price
            int specialPrice =
            (this->parseResults.at(i) / specials[0][0]) * specials[0][1] +
            (this->parseResults.at(i) % specials[0][0]) * this->ruleset.getUnitPrice(i);
            // Getting the special amount, plus the price of any items 'left over'

            int itemsDiff = itemsOriginalPrice - specialPrice;
            this->total -= itemsDiff;
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
    for (auto i: this->getItems())
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
        int itemsOriginalPrice = 
            this->ruleset.getUnitPrice(item) * this->parseResults.at(item);
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

std::map<char, int> Calculator::parse()
{
    if (this->items.empty())
        throw CharListEmpty();
    else if (this->sequence.empty())
        throw StringEmpty();
    // Must check to make sure both the char list
    // and the string sequence are not empty

    std::map<char, int> ret;
    for (auto i : this->items)
    {
        int count = 0;
        for (auto j : this->sequence)
        {
            if (j == i)
                ++count;
        }
        ret.insert(std::make_pair(i, count));
    }
    return ret;
}


int Calculator::calculateTotal()
{
    this->parseResults = this->parse();
    this->calculateSubtotal();
    this->applySpecials();
    return this->total;
}

