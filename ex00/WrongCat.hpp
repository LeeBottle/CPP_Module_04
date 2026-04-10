#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat ( void );
		~WrongCat ( void );
		WrongCat( const WrongCat& other );
		WrongCat& operator=( const WrongCat& other );

		virtual void	makeSound( void ) const;
};

#endif