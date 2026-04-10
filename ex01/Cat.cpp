#include "Cat.hpp"

Cat::Cat ( void )
	: Animal()
{
	brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}
Cat::~Cat ( void )
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}
Cat::Cat( const Cat& other )
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->brain = new Brain();
	*this = other;
}
Cat& Cat::operator=( const Cat& other )
{
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow! Meow!!" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return this->brain;
}