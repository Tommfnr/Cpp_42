#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 151); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
