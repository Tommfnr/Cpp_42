#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(void)
{
    std::cout << "--- addNumber ---\n";
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected: 2)\n";
        std::cout << "longestSpan:  " << sp.longestSpan()  << " (expected: 14)\n";
    }

    std::cout << "\n--- addNumber overflow ---\n";
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        try
        {
            sp.addNumber(4);
            std::cout << "ERROR: should have thrown\n";
        }
        catch (const std::exception&)
        {
            std::cout << "exception OK\n";
        }
    }

    std::cout << "\n--- span on empty/single element ---\n";
    {
        Span empty(5);
        try
        {
            empty.shortestSpan();
            std::cout << "ERROR: should have thrown\n";
        }
        catch (const std::exception&) { std::cout << "shortestSpan on empty: exception OK\n"; }

        Span one(5);
        one.addNumber(42);
        try
        {
            one.longestSpan();
            std::cout << "ERROR: should have thrown\n";
        }
        catch (const std::exception&) { std::cout << "longestSpan on 1 element: exception OK\n"; }
    }

    std::cout << "\n--- addRange (visual, 5 elements) ---\n";
    {
        std::vector<int> src;
        src.push_back(10);
        src.push_back(20);
        src.push_back(30);
        src.push_back(40);
        src.push_back(50);

        Span sp(7);
        sp.addNumber(1);
        sp.addNumber(2);
        std::cout << "before addRange: [1, 2]\n";
        sp.addRange(src.begin(), src.end());
        std::cout << "after  addRange: [1, 2, 10, 20, 30, 40, 50]\n";
        std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected: 1)\n";
        std::cout << "longestSpan:  " << sp.longestSpan()  << " (expected: 49)\n";
    }

    std::cout << "\n--- addRange (10000 elements) ---\n";
    {
        std::vector<int> src;
        for (int i = 0; i < 10000; i++)
            src.push_back(std::rand());

        Span big(10000);
        big.addRange(src.begin(), src.end());
        std::cout << "shortestSpan: " << big.shortestSpan() << '\n';
        std::cout << "longestSpan:  " << big.longestSpan()  << '\n';
    }

    std::cout << "\n--- addRange overflow ---\n";
    {
        std::vector<int> src;
        for (int i = 0; i < 10; i++)
            src.push_back(i);

        Span small(3);
        try
        {
            small.addRange(src.begin(), src.end());
            std::cout << "ERROR: should have thrown\n";
        }
        catch (const std::exception&) { std::cout << "exception OK\n"; }
    }

    return 0;
}
