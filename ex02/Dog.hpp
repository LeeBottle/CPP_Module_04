#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain* brain;

	public:
		Dog ( void );
		virtual ~Dog ( void );
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );

		virtual void	makeSound( void ) const;

		Brain* getBrain(void) const;
};

#endif