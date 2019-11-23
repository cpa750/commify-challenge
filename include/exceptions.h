#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

class CharListEmpty : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Character list empty";
    }
};

class StringEmpty : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: String is empty";
    }
};

class KeyExists : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Key already exists in map";
    }
};

#endif //EXCEPTIONS_H
