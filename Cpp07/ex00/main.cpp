#include "whatever.hpp"
#include <iostream>

int main( void )
{
    std::cout << "--- int ---" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << "--- int (valeurs egales) ---" << std::endl;
    int e = 42;
    int f = 42;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

    std::cout << "--- float ---" << std::endl;
    float x = 1.5f;
    float y = 0.3f;
    ::swap( x, y );
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
    std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

    std::cout << "--- char ---" << std::endl;
    char p = 'z';
    char q = 'a';
    ::swap( p, q );
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "min( p, q ) = " << ::min( p, q ) << std::endl;
    std::cout << "max( p, q ) = " << ::max( p, q ) << std::endl;

    std::cout << "--- string ---" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    // std::cout << "\nmin( c, d ) = " << ::max( c, e ) << std::endl;

    return 0;
}