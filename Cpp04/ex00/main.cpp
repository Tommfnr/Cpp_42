#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Correct Polymorphism -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound(); // Woof
    cat->makeSound(); // Meow
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n----- Wrong Polymorphism -----" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();
    wrong->makeSound(); // WrongAnimal sound
    wrongcat->makeSound(); // WrongCat sound

    delete wrong;
    delete wrongcat;

    return 0;
}
