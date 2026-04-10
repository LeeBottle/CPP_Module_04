#include "Brain.hpp"

Brain::Brain ( void )
{
	std::cout << "Brain Default Constructor called" << std::endl;
}
Brain::~Brain ( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}
Brain::Brain( const Brain& other )
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}
Brain& Brain::operator=( const Brain& other )
{
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "";
}