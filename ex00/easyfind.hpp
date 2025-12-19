#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>

class ValueNotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Valor nao encontrado";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    if (it == container.end())
    {
        throw ValueNotFoundException();
    }

    return it;
}

#endif