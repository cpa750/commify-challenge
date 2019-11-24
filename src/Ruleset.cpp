#include "../include/Ruleset.h"
#include <stdexcept>
#include <utility>
#include <vector>

void Ruleset::addItem(char item, int unitPrice,
              std::vector<std::vector<int>> spec) 
// To represent no specials, pass in an empty 2D vector.
{
    Rule rule;
    rule.unitPrice = unitPrice;
    rule.specials = spec;

    if (!this->contains(item))
        this->rules.insert(std::pair<char, Rule>(item, rule));
    else
        throw KeyExists();
}

void Ruleset::addSpecial(char item,
              std::vector<int> special)
{
    this->rules.at(item).specials.push_back(special);
}

void Ruleset::clearSpecials(char item)
{
    this->rules.at(item).specials.clear();
}

std::vector<char> Ruleset::getItems()
{
    std::vector<char> items;
    for (auto const& i : this->rules)
        items.push_back(i.first);
    return items;
}

bool Ruleset::contains(char character)
// Required as vector::erase doesn't bounds check
{
    if (this->rules.empty()) return false;
    else if (this->rules.find(character) != this->rules.end())
        return true;
    return false;
}

int Ruleset::getUnitPrice(char item)
{   
    return this->rules.at(item).unitPrice;
}

std::vector<std::vector<int>> Ruleset::getSpecials(char item)
{
    return this->rules.at(item).specials;
}

void Ruleset::removeItem(char item)
{
    if (this->contains(item))
            this->rules.erase(item);
    else
        throw std::out_of_range("Error: key not found");
    // Need to check for out of bounds
    // keys with map::remove, unlike map::at
}

void Ruleset::removeSpecial(char item, int index)
// If the special removed was the last, getSpecials returns
// an empty vector.
{
    if (!this->contains(item))
        throw std::out_of_range("Error: key not found");
    else if (this->rules.at(item).specials.size() <= index)
        throw std::out_of_range("Error: list index out of bounds");
    // Need to check for out of bounds
    // indices with vector::erase, unlike map::at
    std::vector<std::vector<int>>& vec = this->rules.at(item).specials;
    vec.erase(vec.begin() + index);
}

void Ruleset::setUnitPrice(char item, int price)
{
    this->rules.at(item).unitPrice = price;
}

