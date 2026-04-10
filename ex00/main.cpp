#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// 1. Animal 클래스 직접 인스턴스화 및 사용 가능 여부 확인
	std::cout << "===== 1. Basic Animal Test =====" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;

	// 2. 상속 및 다형성 확인 (Dog & Cat)
	std::cout << "===== 2. Polymorphism Test (Dog & Cat) =====" << std::endl;
	const Animal* j = new Dog(); // 생성자 호출 순서 확인 (Animal -> Dog)
	const Animal* i = new Cat(); // 생성자 호출 순서 확인 (Animal -> Cat)

	std::cout << "j Type: " << j->getType() << std::endl;
	std::cout << "i Type: " << i->getType() << std::endl;

	std::cout << "j Sound: ";
	j->makeSound(); 
	std::cout << "i Sound: ";
	i->makeSound();

	// 소멸자 호출 순서 확인 (Dog -> Animal 순으로 해제되어야 함)
	// Animal의 소멸자가 virtual이 아니면 Dog의 소멸자가 호출되지 않음
	std::cout << "--- Deleting Dog & Cat ---" << std::endl;
	delete j;
	delete i;

	/*
	// 3. 잘못된 예시 확인 (WrongAnimal & WrongCat)
	std::cout << "===== 3. Wrong Class Test (Non-Virtual) =====" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCatPtr = new WrongCat(); // 부모 포인터로 자식 가리킴
	const WrongCat* realWrongCat = new WrongCat();   // 자식 포인터로 자식 가리킴

	std::cout << "WrongCatPtr Type: " << wrongCatPtr->getType() << std::endl;
	
	std::cout << "[Sound] wrongMeta: ";
	wrongMeta->makeSound();
	
	// virtual이 없으므로 WrongAnimal의 makeSound()가 호출됨
	std::cout << "[Sound] wrongCatPtr (as WrongAnimal*): ";
	wrongCatPtr->makeSound(); 

	// 직접 WrongCat 타입으로 사용할 때만 WrongCat의 소리가 남
	std::cout << "[Sound] realWrongCat (as WrongCat*): ";
	realWrongCat->makeSound();

	std::cout << "--- Deleting Wrong Objects ---" << std::endl;
	delete wrongMeta;
	//delete wrongCatPtr;
	delete realWrongCat;
	*/
	
	return 0;
}