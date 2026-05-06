#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;

    protected:

        virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(const std::string& name, int gradeS, int gradeE);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName() const;
        bool getSigned() const;
        int getGradeS() const;
        int getGradeE() const;

        void beSigned(Bureaucrat &Bureaucrat);
        void execute(Bureaucrat const & executor) const;

        class NotSigned : public std::exception
        {
        public:
            const char* what() const throw();
        };

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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif