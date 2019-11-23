#ifndef RULESET_H
#define RULESET_H

#include "../include/exceptions.h"
#include <cstddef>
#include <map>
#include <vector>


typedef struct Rule
{
    int unitPrice;
    std::vector<std::vector<int>> specials;
} Rule;

class Ruleset
{
private:
    std::map<char, Rule> rules;

public:
    void addItem(char item, int unitPrice,
         std::vector<std::vector<int>> specials={});
    void addSpecial(char item,
         std::vector<int> special);
    void clearSpecials(char item);
    bool contains(char character);
    std::vector<char> getItems();
    int getUnitPrice(char item);
    std::vector<std::vector<int>> getSpecials(char item);
    void removeItem(char item);
    void removeSpecial(char item, int index);
    void setUnitPrice(char item, int price);
};

#endif

