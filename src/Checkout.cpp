#include "../include/Checkout.h"
#include <stdexcept>

Checkout::Checkout(Ruleset rs, bool continuousCalculation) : Calculator(rs)
{
    this->total = 0;
}

int Checkout::getTotal()
{
    if (!this->continuousCalculation)
        this->total = this->calculateTotal();
    // Only need to calculate the total if 
    // continuous calculation is false
    return this->total;
}

void Checkout::scan(char item)
{
    std::string str(1, item);
    try
    {
        this->addItems(str);
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Error: Item does not exist." << std::endl;
    }

    if (this->continuousCalculation)
        this->total = this->calculateTotal();
    // If continuous calculation is true, recalculate
    // the total every time an item is scanned
    // This could get very slow with a high number of items
}

void Checkout::setContinuousCalculation(bool val)
{
    this->continuousCalculation = val;
}

