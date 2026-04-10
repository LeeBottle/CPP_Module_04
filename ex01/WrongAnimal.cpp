#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( void )
	: type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal ( void )
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}
WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = other;
}
WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}


std::string 	WrongAnimal::getType( void ) const
{
	return this->type;
}