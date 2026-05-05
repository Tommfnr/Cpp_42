#include "RobotomyRequestForm.hpp"
#include <time.h>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("drilling", 72, 45), _target("drilling"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other._target, 72, 45), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }

    std::cout << "* drilling noises *\n";

    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully.\n";
    } else {
        std::cout << "Robotomy failed on " << _target << ".\n";
    }
}