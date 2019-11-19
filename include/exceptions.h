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


#endif //EXCEPTIONS_H
