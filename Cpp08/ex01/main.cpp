#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    // test basique du sujet
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << '\n';
    std::cout << "longestSpan:  " << sp.longestSpan() << '\n';

    std::cout << std::endl;

    // exception: container plein
    try
    {
        sp.addNumber(42);
        std::cout << "ERROR: should have thrown\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "addNumber on full Span: exception OK\n";
    }

    std::cout << std::endl;

    // exception: pas assez d'elements pour calculer un span
    Span empty(5);
    try
    {
        empty.shortestSpan();
        std::cout << "ERROR: should have thrown\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "shortestSpan on empty Span: exception OK\n";
    }

    Span one(5);
    one.addNumber(42);
    try
    {
        one.longestSpan();
        std::cout << "ERROR: should have thrown\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "longestSpan on 1-element Span: exception OK\n";
    }

    std::cout << std::endl;

    // test avec 10 000 nombres
    Span big(10000);
    for (int i = 0; i < 10000; i++)
        big.addNumber(std::rand());
    std::cout << "big shortestSpan: " << big.shortestSpan() << '\n';
    std::cout << "big longestSpan:  " << big.longestSpan() << '\n';

    return 0;
}
