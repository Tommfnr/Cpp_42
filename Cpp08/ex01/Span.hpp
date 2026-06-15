#pragma once

#include <vector>

class Span
{
    private:

        unsigned int _N;
        std::vector<int> _tab;
    
    public:
    
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(unsigned int nb);
        int shortestSpan();
        int longestSpan();
};