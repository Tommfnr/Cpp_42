#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}





// #include "ScalarConverter.hpp"

// int main()
// {
//     // Char literal
//     std::cout << "=== char ===" << std::endl;
//     ScalarConverter::convert("'a'");
//     std::cout << std::endl;

//     // Int literals
//     std::cout << "=== int ===" << std::endl;
//     ScalarConverter::convert("0");
//     std::cout << std::endl;
//     ScalarConverter::convert("42");
//     std::cout << std::endl;
//     ScalarConverter::convert("-21474836490");  // INT_MIN
//     std::cout << std::endl;
//     ScalarConverter::convert("2147483647");   // INT_MAX
//     std::cout << std::endl;

//     // Float literals
//     std::cout << "=== float ===" << std::endl;
//     ScalarConverter::convert("3.14f");
//     std::cout << std::endl;
//     ScalarConverter::convert("-0.5f");
//     std::cout << std::endl;

//     // Double literals
//     std::cout << "=== double ===" << std::endl;
//     ScalarConverter::convert("3.14");
//     std::cout << std::endl;
//     ScalarConverter::convert("-42.0");
//     std::cout << std::endl;

//     // Pseudo-literals
//     std::cout << "=== pseudo ===" << std::endl;
//     ScalarConverter::convert("nan");
//     std::cout << std::endl;
//     ScalarConverter::convert("nanf");
//     std::cout << std::endl;
//     ScalarConverter::convert("+inf");
//     std::cout << std::endl;
//     ScalarConverter::convert("-inf");
//     std::cout << std::endl;
//     ScalarConverter::convert("+inff");
//     std::cout << std::endl;
//     ScalarConverter::convert("-inff");
//     std::cout << std::endl;

//     // Cas limites
//     std::cout << "=== edge cases ===" << std::endl;
//     ScalarConverter::convert("0");        // char Non displayable
//     std::cout << std::endl;
//     ScalarConverter::convert("127");      // char max
//     std::cout << std::endl;
//     ScalarConverter::convert("128");      // char impossible
//     std::cout << std::endl;
//     ScalarConverter::convert("notvalid"); // input invalide
//     std::cout << std::endl;

//     //R
//     ScalarConverter::convert("");
//     std::cout << std::endl;

//     return 0;
// }
