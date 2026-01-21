#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== TEST 1 : Destruction polymorphique simple =====" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j; // doit appeler ~Dog puis ~Animal
        delete i; // doit appeler ~Cat puis ~Animal
    }

    std::cout << "\n===== TEST 2 : Tableau d'Animal (polymorphisme) =====" << std::endl;
    {
        const int size = 10;
        Animal* animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n--- Suppression du tableau ---" << std::endl;
        for (int i = 0; i < size; i++)
            delete animals[i]; 
    }

    std::cout << "\n===== TEST 3 : Deep Copy (copie profonde) =====" << std::endl;
    {
        Dog original;
        original.getBrain()->setIdea(0, "Je veux un os");
        original.getBrain()->setIdea(1, "Je veux courir");

        Dog copy(original);

        std::cout << "Original idea[0]: "
                  << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea[0]: "
                  << copy.getBrain()->getIdea(0) << std::endl;
        original.getBrain()->setIdea(0, "Nouvelle idée");

        std::cout << "\nAprès modification de l'original :" << std::endl;
        std::cout << "Original idea[0]: "
                  << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea[0]: "
                  << copy.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << "\n===== FIN DES TESTS =====" << std::endl;
    return 0;
}
