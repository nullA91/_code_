#include "../../Headers/Libraries.h"
#include "../../Headers/SingleLinkedList.h"
#include "../../Headers/DoublyLinkedList.h"

int main(int arg_c, char* arg_v[])
{
	doublyLinkedList<int> test;

	test.addToHead(5);
	test.addToHead(4);
	test.addToHead(3);
	test.addToHead(2);
	test.addToHead(1);
	
	test.addToTail(6);
	test.addToTail(7);
	test.addToTail(8);
	test.addToTail(9);
	test.addToTail(10);
	//test.addToTail(26);

	test.addToPos(0, 1);
	test.addToPos(11, 12);
	
	test.show(); 

	test.swap();
	test.show();

	std::cout << "EXIT" << std::endl;
	system("pause");
	return 0;
}