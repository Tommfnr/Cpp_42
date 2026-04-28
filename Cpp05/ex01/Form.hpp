#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;

    public:
        Form();
        Form(const std::string& name, int gradeS, int gradeE);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getGradeS() const;
        int getGradeE() const;

        class GradeTooHighException : public std::exception
        {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif