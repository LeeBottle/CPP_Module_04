#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// 1. 추상 클래스 인스턴스화 테스트 (컴파일 오류 확인용)
	std::cout << "===== 1. Abstract Class Instantiation Test =====" << std::endl;
	
	// Animal test; 
	// Animal* testPtr = new Animal(); 


	// 2. 구체적인 클래스(Dog, Cat) 생성 및 다형성 확인
	std::cout << "===== 2. Concrete Class & Polymorphism Test =====" << std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n[Type Check]" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n[Sound Check]" << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << "\n--- Deleting Objects ---" << std::endl;
	delete j;
	delete i;


	// 3. 깊은 복사(Deep Copy) 유지 확인
	std::cout << "===== 3. Deep Copy & Brain Test (from ex01) =====" << std::endl;
	
	Dog basic;
	basic.getBrain()->setIdea(0, "Hello World");
	{
		Dog tmp = basic;
		std::cout << "basic brain addr: " << basic.getBrain() << std::endl;
		std::cout << "tmp   brain addr: " << tmp.getBrain() << std::endl;
		
		tmp.getBrain()->setIdea(0, "Bye World");
		std::cout << "basic idea: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "tmp   idea: " << tmp.getBrain()->getIdea(0) << std::endl;
	}

	return 0;
}