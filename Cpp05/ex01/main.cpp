#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "|1 test:\n\n";
    try
    {
        Form f;
        std::cout << f << std::endl;
        
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
        a.incrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n|2 test:\n\n";
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
