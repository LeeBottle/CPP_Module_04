#include "Cat.hpp"

Cat::Cat ( void )
	: Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}
Cat::~Cat ( void )
{
	std::cout << "Cat Destructor called" << std::endl;
}
Cat::Cat( const Cat& other )
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}
Cat& Cat::operator=( const Cat& other )
{
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow! Meow!!" << std::endl;
}