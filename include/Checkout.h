#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "../include/Calculator.h"

class Checkout 
{
private:
    Calculator* calculator;
    bool continuousCalculation;
    int total;

public:
    Checkout(Ruleset rs, bool continuousCalculation=false);

    int getTotal();
    void scan(char item);
    void setContinuousCalculation(bool val);
};

#endif

