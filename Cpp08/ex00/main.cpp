#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(6);

    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, 4);
        std::cout << "vector: found " << *it << '\n';
        std::cout << &vec[1] << " == " << &(*it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "vector: not found\n";
    }

    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, 99);
        std::cout << "vector: found " << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "vector: not found\n";
    }

    std::list<int> ilist;
    ilist.push_back(1);
    ilist.push_back(4);
    ilist.push_back(8);
    ilist.push_back(6);

    try
    {
        std::list<int>::const_iterator it = easyfind(ilist, 6);
        std::cout << "list: found " << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "list: not found\n";
    }

    try
    {
        std::list<int>::const_iterator it = easyfind(ilist, 42);
        std::cout << "list: found " << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "list: not found\n";
    }

    return 0;
}
