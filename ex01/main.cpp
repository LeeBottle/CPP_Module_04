#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// 1. 배열 생성 및 다형성 테스트 (과제 필수 요구사항)
	std::cout << "===== 1. Array of Animals (Dogs & Cats) =====" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++) {
		std::cout << "--Animal[" << i << "] created--" << std::endl;
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// 2. 모든 동물을 사용 가능 여부 확인
	std::cout << "===== 2. Sound Every Animal as Animal* =====" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "--Animal[" << i << "] make sound--" << std::endl;
		std::cout << animals[i]->getType() << "'s sound : ";
		animals[i]->makeSound();
	}

	// 2. 모든 동물을 Animal 삭제 (가상 소멸자 확인)
	std::cout << "===== 3. Deleting Every Animal as Animal* =====" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "--Animal[" << i << "] deleted--" << std::endl;
		delete animals[i];
	}


	// 3. 깊은 복사(Deep Copy) 테스트
	std::cout << "===== Deep Copy Verification =====" << std::endl;

	Dog* basic = new Dog();

	std::cout << "\n--- Creating 'tmp' using Copy Constructor ---" << std::endl;
	{
		Dog tmp = *basic;
		std::cout << "Address of basic's brain: " << basic->getBrain() << std::endl;
		std::cout << "Address of tmp's brain:   " << tmp.getBrain() << std::endl;

		// 복사본(tmp)의 생각을 수정
		tmp.getBrain()->setIdea(0, "Hello World!");
		std::cout << "basic's idea: " << basic->getBrain()->getIdea(0) << std::endl;
		std::cout << "tmp's idea:   " << tmp.getBrain()->getIdea(0) << std::endl;

		// 결과 판정
		if (basic->getBrain()->getIdea(0) != tmp.getBrain()->getIdea(0)) {
			std::cout << "\nDeep Copy" << std::endl;
		} else {
			std::cout << "\nShallow Copy" << std::endl;
		}
		
		std::cout << "\n--- Exiting inner scope: 'tmp' will be destroyed ---" << std::endl;
	}

	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
	{
		Dog tmp;
		tmp = *basic;

		std::cout << "Address of basic's brain: " << basic->getBrain() << std::endl;
		std::cout << "Address of tmp's brain:   " << tmp.getBrain() << std::endl;

		// 복사본(tmp)의 생각을 수정
		tmp.getBrain()->setIdea(0, "Hello World!");
		std::cout << "basic's idea: " << basic->getBrain()->getIdea(0) << std::endl;
		std::cout << "tmp's idea:   " << tmp.getBrain()->getIdea(0) << std::endl;

		// 결과 판정
		if (basic->getBrain() != tmp.getBrain() && 
			basic->getBrain()->getIdea(0) != tmp.getBrain()->getIdea(0)) {
			std::cout << "\nDeep Copy" << std::endl;
		} else {
			std::cout << "\nShallow Copy" << std::endl;
		}

		std::cout << "\n--- Exiting inner scope: 'tmp' will be destroyed ---" << std::endl;
	}

	delete basic;
	return 0;
}