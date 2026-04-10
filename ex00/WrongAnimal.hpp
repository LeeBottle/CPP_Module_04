#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal ( void );
		~WrongAnimal ( void );
		WrongAnimal( const WrongAnimal& other );
		WrongAnimal& operator=( const WrongAnimal& other );

		void	makeSound( void ) const;
		std::string 	getType( void ) const;
};

#endif