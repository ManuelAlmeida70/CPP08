#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class Span
{
    public:
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(unsigned int value);

        template<typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            if (std::distance(begin,end) + _vec.size() > _n)
                throw SpanFullException();

            _vec.insert(_vec.end, begin, end);
        }

        unsigned int longestSpan() const;
        unsigned int shortestSpan() const;
    
    private:
        unsigned int        _n;
        std::vector<int>    _vec;
};

class SpanFullException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "O vector esta cheia!";
        }
};

class NoSpanException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Valor nao encontrado!";
        }
};

#endif