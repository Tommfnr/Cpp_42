#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

AForm::AForm(const std::string& name, int gradeS, int gradeE) : _name(name), _signed(false), _gradeSign(gradeS), _gradeExecute(gradeE)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const{
    return (_name);
}

bool AForm::getSigned() const{
    return (_signed);
}

int AForm::getGradeS() const{
    return (_gradeSign);
}

int AForm::getGradeE() const{
    return (_gradeExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeSign){
        _signed = true;
    }
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw NotSigned();
    if (executor.getGrade() >= _gradeExecute)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::NotSigned::what() const throw(){
    return "Form not signed";
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm name: " << f.getName() << ",\n| Signed: " << (f.getSigned() ? "yes" : "no") << ",\n| Grade to sign: "<< f.getGradeS() << ",\n| Grade to execute: " << f.getGradeS() << ".\n";
    return os;
}