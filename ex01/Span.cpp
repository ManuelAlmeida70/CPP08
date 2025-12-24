#include "Span.hpp"

Span::Span(unsigned int n) : _n(n){}

Span::Span(const Span &copy) : _n(copy._n)
{
    if (this != &copy)
    {
       _vec.clear();

       _vec.insert(_vec.end(), copy._vec.begin(), copy._vec.end());
    }
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _vec.clear();
        _vec.insert(_vec.begin(), other._vec.begin(), other._vec.end());
    }

    return *this;
}

Span::~Span(){}

void Span::addNumber(unsigned int n)
{
    if (_vec.size() >= _n)
    {
        throw SpanFullException();
    }

    _vec.push_back(n);
}


unsigned int Span::longestSpan() const
{
    if (_vec.size() < 2)
    {
        throw NoSpanException();
    }

    std::vector<int>::const_iterator min = std::min_element(_vec.begin(), _vec.end());
    std::vector<int>::const_iterator max = std::max_element(_vec.begin(), _vec.end());

    return static_cast<unsigned int> (*max - *min);
}


unsigned int Span::shortestSpan() const
{
    if (_vec.size() < 2)
    {
        throw NoSpanException();
    }

    std::vector<int> temp(_vec);

    std::sort(temp.begin(), temp.end());

    unsigned int minDiff = temp[1] - temp[0];

    for (size_t i = 2; i < temp.size(); i++)
    {
        unsigned int diff = temp[i] - temp[i - 1];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }

    return minDiff;
}