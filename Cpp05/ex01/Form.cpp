#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

Form::Form(const std::string& name, int gradeS, int gradeE) : _name(name), _signed(false), _gradeSign(gradeS), _gradeExecute(gradeE)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const{
    return (_name);
}

bool Form::getSigned() const{
    return (_signed);
}

int Form::getGradeS() const{
    return (_gradeSign);
}

int Form::getGradeE() const{
    return (_gradeExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeSign){
        _signed = true;
    }
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form name: " << f.getName() << ",\n| Signed: " << (f.getSigned() ? "yes" : "no") << ",\n| Grade to sign: "<< f.getGradeS() << ",\n| Grade to execute: " << f.getGradeS() << ".\n";
    return os;
}