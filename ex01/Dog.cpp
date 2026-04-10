#include "Dog.hpp"

Dog::Dog ( void )
	: Animal()
{
	brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}
Dog::~Dog ( void )
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}
Dog::Dog( const Dog& other )
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->brain = new Brain();
	*this = other;
}
Dog& Dog::operator=( const Dog& other )
{
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Bark! Bark!!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return this->brain;
}