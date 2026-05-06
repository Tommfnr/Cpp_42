#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main()
{
    // ---- Grade invalide ----
    separator("Invalid grade at construction");
    try { Bureaucrat b("Too High", 0); }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    try { Bureaucrat b("Too Low", 151); }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    // ---- Signer avec grade insuffisant ----
    separator("Sign: grade too low");
    try
    {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Zaphod");
        intern.signForm(pardon); // grade requis: 25
    }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    // ---- Exécuter sans avoir signé ----
    separator("Execute: form not signed");
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robo("R2D2");
        boss.executeForm(robo);
    }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    // ---- Exécuter avec grade insuffisant ----
    separator("Execute: grade too low");
    try
    {
        Bureaucrat mid("Mid", 100);
        RobotomyRequestForm robo("Bender"); // exec requis: 45
        Bureaucrat boss("Boss", 1);
        boss.signForm(robo);
        mid.executeForm(robo);
    }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    // ---- Cas valides pour les 3 formulaires ----
    separator("Valid execution: all 3 forms");
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm   robo("Wall-E");
        PresidentialPardonForm pardon("Arthur Dent");

        boss.signForm(shrub);   boss.executeForm(shrub);
        boss.signForm(robo);    boss.executeForm(robo);
        boss.signForm(pardon);  boss.executeForm(pardon);
    }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    // ---- Aléatoire robotomy ----
    separator("Robotomy x5 (random 50%)");
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robo("Marvin");
        boss.signForm(robo);
        for (int i = 0; i < 5; i++){
            boss.executeForm(robo);
            std::cout << std::endl;
        }
    }
    catch (std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; }

    return 0;
}