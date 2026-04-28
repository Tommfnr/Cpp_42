#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=========== 1 test: ===========\n\n";
    try
    {
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

    std::cout << "\n=========== 2 test: ===========\n\n";
    try
    {
        Bureaucrat b("Bob", 151); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 3 test: ===========\n\n";
    try
    {
        Form f("Papier", 20, 1);
        std::cout << f << std::endl;

        Bureaucrat a("Matheo", 127);
        std::cout << a << std::endl;

        Bureaucrat b("Raff", 13);
        std::cout << b << std::endl;

        a.signForm(f);
        b.signForm(f);

        Form h("hmm", 20, -10);
        
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
