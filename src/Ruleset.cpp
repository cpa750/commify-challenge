#include "../include/Ruleset.h"
#include <stdexcept>
#include <utility>
#include <vector>

void Ruleset::addItem(char item, int unitPrice,
              std::vector<std::vector<int>> spec) 
// Method to add an item rule to the ruleset.
// Takes the item character, unit price, and a 2D vector
// representing the specials. To represent no specials,
// pass in an empty 2D vector.
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
// Method to add a special to an already existing
// item rule.
// Takes the item to add the special to and a vector
// representing the special.
{
    this->rules.at(item).specials.push_back(special);
}

void Ruleset::clearSpecials(char item)
// Method to clear all the specials for 
// an item rule in the ruleset.
// Takes the item to clear the specials for.
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
// Private method to check whether an item
// is contained in the ruleset. This is required
// as vector::erase does not bounds-check.
{
    if (this->rules.empty()) return false;
    else if (this->rules.find(character) != this->rules.end())
        return true;
    return false;
}

int Ruleset::getUnitPrice(char item)
// Method for getting the unit price for an item
// in the ruleset.
// Takes the item to get the price for.
// Returns the price of the item.
{   
    return this->rules.at(item).unitPrice;
}

std::vector<std::vector<int>> Ruleset::getSpecials(char item)
// Method for getting the specials for an item in the ruleset.
// Takes the item to get the specials for.
// Returns a 2D vector of the specials.
{
    return this->rules.at(item).specials;
}

void Ruleset::removeItem(char item)
// Method for removing an item in the ruleset.
// Takes the item character to delete.
// Throws out_of_bounds if the item is not in the ruleset. 
{
    if (this->contains(item))
            this->rules.erase(item);
    else
        throw std::out_of_range("Error: key not found");
    // Need to check for out of bounds
    // keys with map::remove, unlike map::at
}

void Ruleset::removeSpecial(char item, int index)
// Method for removing a special from an item in the ruleset.
// Takes the item character and the special index in the
// Throws out_of_bounds if the item is not in the ruleset or
// if the special index is out of bounds.
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
// Method for setting the unit price of an item.
// Takes the item character and the price to set.
{
    this->rules.at(item).unitPrice = price;
}

