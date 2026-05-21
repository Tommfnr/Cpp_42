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

// ─── Fonctions de détection ──────────────────────────────────────────────────

// Un pseudo-literal est une valeur spéciale comme nan, +inf, -inf (et leurs variantes float)
static bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "nanf"
            || s == "+inf"  || s == "-inf"
            || s == "+inff" || s == "-inff");
}

// Un char literal est de la forme 'x' (exactement 3 caractères)
static bool isChar(const std::string &s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

// Un float se termine par 'f' et contient un point décimal, ex: 3.14f
static bool isFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    // On enlève le 'f' final et on vérifie que le reste est un nombre décimal
    std::string withoutF = s.substr(0, s.length() - 1);
    char *end;
    strtod(withoutF.c_str(), &end);
    return (*end == '\0' && withoutF.find('.') != std::string::npos);
}

// Un double contient un point décimal mais pas de 'f' final, ex: 3.14
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

// Détermine le type du literal reçu en argument
static e_type detectType(const std::string &s)
{
    if (isPseudo(s))   return PSEUDO;
    if (isChar(s))     return CHAR;
    if (isFloat(s))    return FLOAT;
    if (isDouble(s))   return DOUBLE;
    if (isInt(s))      return INT;
    return DOUBLE; // fallback : on essaie comme double
}

// ─── Fonctions d'affichage ───────────────────────────────────────────────────

// Affiche le char correspondant à la valeur
// "Non displayable" si le caractère n'est pas imprimable (ASCII < 32 ou == 127)
// "impossible" si la valeur est hors de la plage ASCII ou n'est pas un nombre
static void printChar(double val)
{
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

// Affiche l'int correspondant à la valeur
// "impossible" si la valeur déborde d'un int ou n'est pas un nombre
static void printInt(double val)
{
    if (std::isnan(val) || std::isinf(val)
        || val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

// Affiche le float correspondant à la valeur
// Les pseudo-literals ont leur propre représentation (nanf, +inff, -inff)
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

// Affiche le double correspondant à la valeur
// Les pseudo-literals ont leur propre représentation (nan, +inf, -inf)
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

// ─── Méthode principale ──────────────────────────────────────────────────────

// Reçoit une string, détecte son type, puis affiche les 4 conversions scalaires
void ScalarConverter::convert(const std::string &literal)
{
    e_type type = detectType(literal);

    // On stocke tout en double pour centraliser les conversions
    // Le double peut représenter tous les types scalaires sans perte critique
    double val = 0.0;

    if (type == CHAR)
        // Le char literal est de la forme 'x', on prend le caractère à l'index 1
        val = static_cast<double>(literal[1]);
    else if (type == PSEUDO)
    {
        // Les pseudo-literals ne sont pas parsables via strtod, on les affecte manuellement
        if (literal == "nan" || literal == "nanf")
            val = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            val = std::numeric_limits<double>::infinity();
        else // -inf ou -inff
            val = -std::numeric_limits<double>::infinity();
    }
    else if (type == FLOAT)
        // On enlève le 'f' final avant de parser
        val = strtod(literal.substr(0, literal.length() - 1).c_str(), NULL);
    else
        // INT ou DOUBLE : strtod parse les deux
        val = strtod(literal.c_str(), NULL);

    // Affichage des 4 types
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}
