#include <iostream>
#include <cstring>
#include "Serializer.hpp"

int main()
{
    Data original;
    original.id = 42;
    original.value = 3.14f;
    std::strncpy(original.name, "hello", 31);

    std::cout << "Original pointer : " << &original << std::endl;
    std::cout << "id    : " << original.id << std::endl;
    std::cout << "value : " << original.value << std::endl;
    std::cout << "name  : " << original.name << std::endl;
    std::cout << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t) : " << raw << std::endl;
    std::cout << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer : " << recovered << std::endl;
    std::cout << "id    : " << recovered->id << std::endl;
    std::cout << "value : " << recovered->value << std::endl;
    std::cout << "name  : " << recovered->name << std::endl;
    std::cout << std::endl;

    if (recovered == &original)
        std::cout << "Pointers match: OK" << std::endl;
    else
        std::cout << "Pointers do NOT match: FAIL" << std::endl;

    return 0;
}
