#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string& ref = str;

    std::cout << "Memory address: " << &str << std::endl;
    std::cout << "Memory address: " << ptr << std::endl;
    std::cout << "Memory address: " << &ref << std::endl;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value ptr: " << *ptr << std::endl;
    std::cout << "Value ref: " << ref << std::endl;
}


