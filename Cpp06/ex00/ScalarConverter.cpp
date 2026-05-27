#include "ScalarConverter.hpp"
#include <cstdlib>   // strtod, strtol
#include <climits>   // INT_MIN, INT_MAX
#include <cmath>     // isnan, isinf
#include <iomanip>   // setprecision, fixed
#include <limits>    // numeric_limits

// Les types que l'on peut détecter dans la string
enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO  // nan, inf, etc.
};

// ─── Forme canonique (privée = non instanciable) ─────────────────────────────

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "nanf"
            || s == "+inf"  || s == "-inf"
            || s == "+inff" || s == "-inff");
}

static bool isChar(const std::string &s) {
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    std::string withoutF = s.substr(0, s.length() - 1);
    char *end;
    strtod(withoutF.c_str(), &end);
    return (*end == '\0' && withoutF.find('.') != std::string::npos);
}

static bool isDouble(const std::string &s)
{
    if (s.empty())
        return false;
    char *end;
    strtod(s.c_str(), &end);
    return (*end == '\0' && s.find('.') != std::string::npos);
}

// Un int ne contient que des chiffres (avec éventuel '-' en début), ex: 42
static bool isInt(const std::string &s)
{
    if (s.empty())
        return false;
    char *end;
    strtol(s.c_str(), &end, 10);
    return (*end == '\0');
}

static e_type detectType(const std::string &s)
{
    if (isPseudo(s))   return PSEUDO;
    if (isChar(s))     return CHAR;
    if (isFloat(s))    return FLOAT;
    if (isDouble(s))   return DOUBLE;
    if (isInt(s))      return INT;
    return DOUBLE; // fallback
}

static void printChar(double val)
{
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val)
{
    if (std::isnan(val) || std::isinf(val)
        || val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val)
{
    float f = static_cast<float>(val);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" << std::endl;
    else
    {
        // fixed + setprecision(1) garantit au moins un chiffre après la virgule
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

static void printDouble(double val)
{
    if (std::isnan(val))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(val))
        std::cout << "double: " << (val > 0 ? "+" : "-") << "inf" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << val << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Nothing turn in!\n";
        return ;
    }
    e_type type = detectType(literal);

    double val = 0.0;

    if (type == CHAR)
        val = static_cast<double>(literal[1]);
    else if (type == PSEUDO)
    {
        if (literal == "nan" || literal == "nanf")
            val = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            val = std::numeric_limits<double>::infinity();
        else
            val = -std::numeric_limits<double>::infinity();
    }
    else if (type == FLOAT)
        val = strtod(literal.substr(0, literal.length() - 1).c_str(), NULL);
    else
        val = strtod(literal.c_str(), NULL);

    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}
