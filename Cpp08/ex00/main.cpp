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
        easyfind(vec, 10);
    }
    catch(const std::exception& e)
    {
        std::cout << "not found" << '\n';
    }

    std::list<int> ilist;
    ilist.push_back(1);
    ilist.push_back(4);
    ilist.push_back(8);
    ilist.push_back(6);
    try
    {
        easyfind(ilist, 6);
    }
    catch(const std::exception& e){
        std::cout << "not found" << '\n';
    }

    std::list<char> clist;
    clist.push_back('c');
    clist.push_back(';');
    clist.push_back('h');
    clist.push_back('p');
    clist.push_back(97);
    try
    {
        easyfind(clist, 'a');
        easyfind(clist, ';');
    }
    catch(const std::exception& e){
        std::cout << "not found" << '\n';
    }

}