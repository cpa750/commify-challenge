#ifndef RULESET_H
#define RULESET_H

#include <cstddef>
#include <map>

typedef struct Rule
{
    int unitPrice;
    int specialNo;
    int specialPrice;
} Rule;

class Ruleset
{
private:
    std::map<char, Rule> rules;

public:
    void add(char item, int unitPrice,
            int specialNo, int specialPrice);
    void get(char item);
    void remove(char item);

};

#endif

