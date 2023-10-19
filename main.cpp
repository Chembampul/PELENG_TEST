#include <iostream>
#include "QueueNode.h"
#include "CycledQueue.h"
#include "QueueIterator.h"
#include "CycledQueue.cpp"
#include "QueueNode.cpp"

#define LENGTH 5

int main() {
	CycledQueue<int> test(LENGTH);
	for (int i = 0; i < LENGTH; i++) {
		test.push(i + 1);
	}
	test.print();
	test.push(6);
	test.push(7);
	test.print();
	auto iterator = test.begin();
	std::cout << *iterator << std::endl;
	std::cout << test[4] << std::endl;
	std::cout << iterator + 36 << std::endl;
	std::cout << *(iterator += 2) << std::endl;
	test.pop();
	test.pop();
	test.pop();
	test.print();
	system("pause");
	return 0;
}