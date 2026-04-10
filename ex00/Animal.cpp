#include "Animal.hpp"

Animal::Animal ( void )
	: type("Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}
Animal::~Animal ( void )
{
	std::cout << "Animal Destructor called" << std::endl;
}
Animal::Animal( const Animal& other )
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}
Animal& Animal::operator=( const Animal& other )
{
	std::cout << "Animal Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal Sound" << std::endl;
}


std::string 	Animal::getType( void ) const
{
	return this->type;
}