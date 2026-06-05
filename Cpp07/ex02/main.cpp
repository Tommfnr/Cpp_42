#include "Array.hpp"

int main(void)
{
    Array<int> a;
    std::cout << a.size() << std::endl;
    std::cout << std::endl;

    Array<int> b(5);
    std::cout << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << ",";
    std::cout << std::endl;
    std::cout << std::endl;

    Array<int> c(b);
    std::cout << "avant c: " << c[0] << " b: " << b[0] << std::endl;
    c[0] = 42;
    std::cout << "apres c: " << c[0] << " b: " << b[0] << std::endl;
    std::cout << std::endl;

    Array<int> d;
    d = b;
    std::cout << "avant d: " << d[0] << " b: " << b[0] << std::endl;
    d[0] = 99;
    std::cout << "apres d: " << d[0] << " b: " << b[0] << std::endl;
    std::cout << std::endl;

    try{
        b[10];
    }
    catch (std::exception& e){
        std::cout << "Error\n";
    }
}