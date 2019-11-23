#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "../include/Calculator.h"

class Checkout: Calculator
{
private:
    int total;
    bool continuousCalculation;

public:
    Checkout(Ruleset rs, bool continuousCalculation=false);

    int getTotal();
    void scan(char item);
    void setContinuousCalculation(bool val);
};

#endif

