#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(){
    _N = 0;
}

Span::Span(unsigned int N) {
    _N = N;
}


Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other){
        this->_N = other._N;
        this->_tab = other._tab;
    }
    return (*this);
}

Span::~Span() {}


void Span::addNumber(unsigned int nb) {
    if (_N <= _tab.size())
        throw std::exception();
    _tab.push_back(nb);
}

int Span::shortestSpan() {
    if (_tab.size() < 2)
        throw std::exception();

    std::sort(_tab.begin(), _tab.end());

    int shortest = _tab[1] - _tab[0];
    for (size_t i = 0; i < _tab.size() - 1; i++)
        if (shortest > (_tab[i + 1] - _tab[i]))
            shortest = (_tab[i + 1] - _tab[i]);

    return (shortest);
}

int Span::longestSpan() {
    if (_tab.size() < 2)
        throw std::exception();

    std::sort(_tab.begin(), _tab.end());

    return (*(_tab.end() - 1) - *_tab.begin());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (end < begin)
        throw std::exception();

    int dist = std::distance(begin, end);
    if (_tab.size() + dist > _N)
        throw std::exception();

    _tab.insert(_tab.end(), begin, end);
}

