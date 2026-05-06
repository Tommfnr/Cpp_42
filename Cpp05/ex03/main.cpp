#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main()
{
    // ---- Formulaires valides ----
    separator("Intern: valid forms");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm* f1 = intern.makeForm("robotomy request", "Bender");
        AForm* f2 = intern.makeForm("shrubbery creation", "tree");
        AForm* f3 = intern.makeForm("presidential pardon", "Macron");

        if (f1) { boss.signForm(*f1); boss.executeForm(*f1); delete f1; }
        if (f2) { boss.signForm(*f2); boss.executeForm(*f2); delete f2; }
        if (f3) { boss.signForm(*f3); boss.executeForm(*f3); delete f3; }
    }

    // ---- Formulaire inconnu ----
    separator("Intern: unknown form");
    {
        Intern intern;
        AForm* f = intern.makeForm("coffee request", "Boss");
        if (f)
            delete f;
    }

    return 0;
}