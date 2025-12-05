
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class   Zombie{
    
    private:
        
        std::string _name;

    public:
        
        void Setname(std::string name);
        Zombie(std::string name);
        Zombie( void );
        ~Zombie( void );
        void announce( void ) const;
        
}  ;
    
Zombie* zombieHorde( int N, std::string name );

#endif

