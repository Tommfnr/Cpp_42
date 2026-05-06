#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pardoned", 25, 5), _target("pardoned"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    :AForm(target, 25, 5), _target(target)  {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}