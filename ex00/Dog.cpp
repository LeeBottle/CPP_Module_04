#include "Dog.hpp"

Dog::Dog ( void )
	: Animal()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}
Dog::~Dog ( void )
{
	std::cout << "Dog Destructor called" << std::endl;
}
Dog::Dog( const Dog& other )
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}
Dog& Dog::operator=( const Dog& other )
{
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Bark! Bark!!" << std::endl;
}