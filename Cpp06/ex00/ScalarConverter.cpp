#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>
#include <limits>

enum e_type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string &s)
{
    return s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff";
}

static bool isChar(const std::string &s)
{
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return true;
    if (s.length() == 1 && std::isprint(static_cast<unsigned char>(s[0])) && !std::isdigit(static_cast<unsigned char>(s[0])))
        return true;
    return false;
}

static bool isFloat(const std::string &s)
{
    if (s[s.length() - 1] != 'f')
        return false;
    std::string num = s.substr(0, s.length() - 1);
    char *end;
    strtod(num.c_str(), &end);
    return *end == '\0' && num.find('.') != std::string::npos;
}

static bool isDouble(const std::string &s)
{
    char *end;
    strtod(s.c_str(), &end);
    return *end == '\0' && s.find('.') != std::string::npos;
}

static bool isInt(const std::string &s)
{
    char *end;
    strtol(s.c_str(), &end, 10);
    return *end == '\0';
}

static e_type detectType(const std::string &s)
{
    if (isPseudo(s)) return PSEUDO;
    if (isChar(s))   return CHAR;
    if (isFloat(s))  return FLOAT;
    if (isDouble(s)) return DOUBLE;
    if (isInt(s))    return INT;
    return INVALID;
}

static void printCharLine(double val)
{
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (static_cast<int>(val) < 32 || static_cast<int>(val) == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printIntLine(double val)
{
    if (std::isnan(val) || std::isinf(val) || val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloatLine(float f)
{
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
}

static void printDoubleLine(double d)
{
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+" : "-") << "inf" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void printFromChar(char c)
{
    printCharLine(static_cast<double>(c));
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloatLine(static_cast<float>(c));
    printDoubleLine(static_cast<double>(c));
}

static void printFromInt(int i)
{
    printCharLine(static_cast<double>(i));
    std::cout << "int: " << i << std::endl;
    printFloatLine(static_cast<float>(i));
    printDoubleLine(static_cast<double>(i));
}

static void printFromFloat(float f)
{
    printCharLine(static_cast<double>(f));
    printIntLine(static_cast<double>(f));
    printFloatLine(f);
    printDoubleLine(static_cast<double>(f));
}

static void printFromDouble(double d)
{
    printCharLine(d);
    printIntLine(d);
    printFloatLine(static_cast<float>(d));
    printDoubleLine(d);
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Error: empty input" << std::endl;
        return ;
    }

    e_type type = detectType(literal);

    if (type == INVALID)
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    if (type == CHAR)
    {
        char c = (literal.length() == 1) ? literal[0] : literal[1];
        printFromChar(c);
    }
    else if (type == INT)
    {
        double check = strtod(literal.c_str(), NULL);
        if (check < static_cast<double>(INT_MIN) || check > static_cast<double>(INT_MAX))
            printFromDouble(check);
        else
            printFromInt(static_cast<int>(strtol(literal.c_str(), NULL, 10)));
    }
    else if (type == FLOAT)
    {
        float f = static_cast<float>(strtod(literal.substr(0, literal.length() - 1).c_str(), NULL));
        printFromFloat(f);
    }
    else if (type == DOUBLE)
    {
        printFromDouble(strtod(literal.c_str(), NULL));
    }
    else // PSEUDO
    {
        double d;
        if (literal == "nan"  || literal == "nanf")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
        printFromDouble(d);
    }
}
