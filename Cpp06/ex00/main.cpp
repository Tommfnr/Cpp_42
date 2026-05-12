#include "ScalarConverter.hpp"

int main()
{
    // Char literal
    std::cout << "=== char ===" << std::endl;
    ScalarConverter::convert("'a'");
    std::cout << std::endl;

    // Int literals
    std::cout << "=== int ===" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483648");  // INT_MIN
    std::cout << std::endl;
    ScalarConverter::convert("2147483647");   // INT_MAX
    std::cout << std::endl;

    // Float literals
    std::cout << "=== float ===" << std::endl;
    ScalarConverter::convert("3.14f");
    std::cout << std::endl;
    ScalarConverter::convert("-0.5f");
    std::cout << std::endl;

    // Double literals
    std::cout << "=== double ===" << std::endl;
    ScalarConverter::convert("3.14");
    std::cout << std::endl;
    ScalarConverter::convert("-42.0");
    std::cout << std::endl;

    // Pseudo-literals
    std::cout << "=== pseudo ===" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    // Cas limites
    std::cout << "=== edge cases ===" << std::endl;
    ScalarConverter::convert("0");        // char Non displayable
    std::cout << std::endl;
    ScalarConverter::convert("127");      // char max
    std::cout << std::endl;
    ScalarConverter::convert("128");      // char impossible
    std::cout << std::endl;
    ScalarConverter::convert("notvalid"); // input invalide

    return 0;
}
