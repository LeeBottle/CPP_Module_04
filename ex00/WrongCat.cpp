#include "WrongCat.hpp"

WrongCat::WrongCat ( void )
	: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}
WrongCat::~WrongCat ( void )
{
	std::cout << "WrongCat Destructor called" << std::endl;
}
WrongCat::WrongCat( const WrongCat& other )
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = other;
}
WrongCat& WrongCat::operator=( const WrongCat& other )
{
	std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat Sound" << std::endl;
}