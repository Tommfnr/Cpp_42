#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

struct FormEntry {
    std::string name;
    AForm*      (*create)(const std::string& target);
};

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    const FormEntry forms[] = {
        {"robotomy request",    createRobotomy},
        {"presidential pardon", createPardon},
        {"shrubbery creation",  createShrubbery}
    };
    const int size = 3;

    for (int i = 0; i < size; i++)
    {
        if (forms[i].name == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Intern: unknown form '" << name << "'" << std::endl;
    return NULL;
}