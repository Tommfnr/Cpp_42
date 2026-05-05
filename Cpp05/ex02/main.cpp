#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// #include "Intern.hpp" // décommente si ex03

int main()
{
    std::cout << "=========== 1: Basic execution ===========\n\n";
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 2: Execute without signing ===========\n\n";
    try
    {
        Bureaucrat bob("Bob", 1);
        RobotomyRequestForm robo("R2D2");

        bob.executeForm(robo); // doit throw (not signed)
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 3: Grade too low to execute ===========\n\n";
    try
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm shrub("garden");

        low.signForm(shrub);       // peut passer (grade 145)
        low.executeForm(shrub);    // doit throw (grade trop bas)
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 4: Robotomy randomness ===========\n\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robo("Wall-E");

        boss.signForm(robo);

        for (int i = 0; i < 5; i++)
            boss.executeForm(robo); // succès ~50%
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 5: Shrubbery file creation ===========\n\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("park");

        boss.signForm(shrub);
        boss.executeForm(shrub); // crée park_shrubbery
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ====== BONUS EX03 ======
    /*
    std::cout << "\n=========== 6: Intern ===========\n\n";
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        Form* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
        Form* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
        Form* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        boss.signForm(*f1);
        boss.executeForm(*f1);

        boss.signForm(*f2);
        boss.executeForm(*f2);

        boss.signForm(*f3);
        boss.executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;

        // test erreur
        Form* f4 = someRandomIntern.makeForm("unknown form", "???");
        delete f4;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    */

    return 0;
}