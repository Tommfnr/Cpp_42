#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal* animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 10; i++)
        delete animals[i]; // polymorphisme + destructeurs virtuels

    // TEST DEEP COPY
    Dog a;
    a.getBrain()->setIdea(0, "I love bones");

    Dog b = a;
    b.getBrain()->setIdea(0, "I love cats");

    std::cout << a.getBrain()->getIdea(0) << std::endl; // bones
    std::cout << b.getBrain()->getIdea(0) << std::endl; // cats
}

