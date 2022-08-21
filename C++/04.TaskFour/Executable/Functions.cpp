#include "../Headers/Functions.h"

// меню шаблонных функций
void _menu_template_functions()
{
	int choise = 0;

	const size_t size = 5;
	const size_t length = 75;
	
	std::string menu_options[size] = \
	{
		"1. search for the arithmetic mean of an array",
			"2. finding roots of linear and quadratic equations",
			"3. search for the maximum value",
			"4. search for the minimum value",
			"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		std::cout << "select menu item: ";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
			case 1:
			{
				const unsigned int size = 10;

				int set_numbers[size];
				
				for (size_t i = 0; i < size; ++i)
				{
					std::cout << "enter " << i + 1 << " value: ";
					std::cin >> set_numbers[i];
				}
				std::cout << "arithmetic mean of the array: " << _arithmetic_mean(set_numbers, size) << std::endl;
			}
			break;
			case 2:
			{
				double a = 0.0;
				double b = 0.0;
				double c = 0.0;
				double x = 0.0;

				std::pair<double, double> roots;
				// линейное уравнение
				std::cout << "enter first variable: ";
				std::cin >> a;
				std::cout << "enter second variable: ";
				std::cin >> b;

				x = _linear_equation_root(a, b);
				std::cout << "the root of the equation: " << x << std::endl;
				// квадратное уравнение
				std::cout << "enter first variable: ";
				std::cin >> a;
				std::cout << "enter second variable: ";
				std::cin >> b;
				std::cout << "enter third variable: ";
				std::cin >> c;
				
				roots = _quadratic_equation_root(a, b, c);
				std::cout << "roots of the quadratic equation: " << roots.first << '\t' << roots.second << std::endl;
			}
			break;
			case 3:
			{
				double first_value = 0.0;
				double second_value = 0.0;

				std::cout << "enter first value: ";
				std::cin >> first_value;
				std::cout << "enter second value: ";
				std::cin >> second_value;

				std::cout << "maximum value: " << _max_value(first_value, second_value) << std::endl;
			}
			break;
			case 4:
			{
				double first_value = 0.0;
				double second_value = 0.0;

				std::cout << "enter first value: ";
				std::cin >> first_value;
				std::cout << "enter second value: ";
				std::cin >> second_value;

				std::cout << "minimum value: " << _min_value(first_value, second_value) << std::endl;
			}
			break;
			case 0:
				std::cout << "complete programm" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		system("pause");
	} while (choise);
}
// меню функций массива
void _menu_array_functions()
{
	int choise = 0;

	const size_t size = 17;
	const size_t length = 75;

	array<double> array_first;
	array<double> array_second;

	std::string menu_options[size] = \
	{
		"1. adding an element to an array",
		"2. inserting an element at a specified position",
		"3. setting a new value for a specific element",
		"4. setting the size of an array",
		"5. getting a specific element (by index)",
		"6. getting the address of an array with data",
		"7. getting the last valid index in the array",
		"8. getting the size of an array",
		"9. checking an array for emptiness",
		"10. addition of two arrays",
		"11. removing an element from a given position",
		"12. remove excess memory",
		"13. delete all",
		"14. displaying array elements",
		"15. writing data to a file",
		"16. reading data from a file",
		"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		std::cout << "select menu item: ";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
			case 1:
			{
				double value = 0.0;
				
				std::cout << "enter value to be added to array: ";
				std::cin >> value;
				if (array_first.add(value) == true)
					std::cout << "element added successfully" << std::endl;
				else
					std::cout << "error, element was not added to the array" << std::endl;

				break;
			}
			case 2:
			{
				double value = 0.0;

				unsigned int index = 0;

				std::cout << "enter value to be added to array: ";
				std::cin >> value;
				
				INDEX:
				std::cout << "enter the position of the added element: ";
				std::cin >> index;

				if (index <= array_first.getSize() && index > 0)
				{
					if (array_first.insertAt(value, index) == true)
						std::cout << "element added at specified position" << std::endl;
					else
						std::cout << "error, element not added at specified position" << std::endl;
				}
				else goto INDEX;

				break;
			}
			case 3:
			{
				double value = 0.0;

				unsigned int index = 0;

				std::cout << "enter value to be added to array: ";
				std::cin >> value;
				
				ENTERINDEX:
				std::cout << "enter the position of the added element: ";
				std::cin >> index;

				if (index <= array_first.getSize() && index > 0)
					array_first.setAt(value, index);
				else goto ENTERINDEX;

				break;
			}
			case 4:
			{
				size_t size = 0;

				std::cout << "enter the new size of the array" << std::endl;
				std::cin >> size;

				array_first.setSize(size);

				break;
			}
			case 5:
			{
				double value = 0.0;

				unsigned int index = 0;

				_INDEX:
				std::cout << "enter the position of the element whose value you want to get: ";
				std::cin >> index;
				if (!array_first.isEmpty())
				{
					if (index > 0 && index <= array_first.getElementCount())
						value = array_first.getAt(index);
					else goto _INDEX;

					std::cout << "received value: " << value << std::endl;
				}
				else
					std::cout << "array is empty add elements to array" << std::endl;

				break;
			}
			case 6:
				std::cout << "address of the beginning of the array: " << array_first.getArrayAddress() << std::endl;
				break;
			case 7:
				if (!array_first.isEmpty())
					std::cout << "last valid array index: " << array_first.getUpperBound() << std::endl;
				else
					std::cout << "array is empty add elements to array" << std::endl;
				break;
			case 8:
				std::cout << "size of allocated memory for array: " << array_first.getSize() * sizeof(double) << std::endl;
				break;
			case 9:
				if (array_first.isEmpty())
					std::cout << "array is empty" << std::endl;
				else
					std::cout << "array contains values" << std::endl;
				break;
			case 10:
			{
				size_t size = 0;

				array<double> array_first;
				array<double> array_second;
				array<double> array_third;

			SIZEF:
				std::cout << "enter size of first array: ";
				std::cin >> size;
				if (size > 0)
					array_first.setSize(size);
				else goto SIZEF;

			SIZES:
				std::cout << "enter size of second array: ";
				std::cin >> size;
				if (size > 0)
					array_second.setSize(size);
				else goto SIZES;

				for (size_t i = 0; i < array_first.getSize(); ++i)
				{
					std::cout << "enter " << i + 1 << " value of the first array: ";
					std::cin >> array_first[i];
				}

				for (size_t i = 0; i < array_first.getSize(); ++i)
				{
					std::cout << "enter " << i + 1 << " value of the second array: ";
					std::cin >> array_second[i];
				}

				array_third = array_first.append(array_second);
				std::cout << "\t\tresult\n";
				array_third.show();

				break;
			}
			case 11:
			{
				unsigned int index = 0;

				INDEX_:
				std::cout << "enter the position of the added element: ";
				std::cin >> index;
				if (index > 0 && index <= array_first.getElementCount())
					array_first.removeAt(index);
				else goto INDEX_;

				break;
			}
			case 12:
				array_first.freeExtra();
				break;
			case 13:
				array_first.removeAll();
				break;
			case 14:
				array_first.show();
				break;
			case 15:
				array_first.fileWrite("../../Files/array.txt");
				break;
			case 16:
				array_first.fileRead("../../Files/array.txt");
				break;
			//////////////////////////////////
			case 0:
				std::cout << "complete programm" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		system("pause");
	} while (choise);
}
// меню функций стека
void _menu_stack_functions()
{
	int choise = 0;
	int value = 0;

	const size_t size = 11;
	const size_t length = 75;

	stack<int, 10> stack_main;

	std::string menu_options[size] = \
	{
		"1. pushing a character onto the stack",
		"2. pop a character from the stack",
		"3. counting number of characters on the stack",
		"4. checking the stack for empty",
		"5. checking if stack is full",
		"6. stack cleanup",
		"7. stack element display",
		"8. displaying stack elements",
		"9. writing data to a file",
		"10. reading data from a file",
		"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		std::cout << "select menu item: ";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
			case 1:
				std::cout << "enter value: ";
				std::cin >> value;
				stack_main.push(value);
				break;
			case 2:
				if (!stack_main.empty())
					value = stack_main.pop();
				std::cout << "value: " << value << std::endl;
				break;
			case 3:
				if (!stack_main.empty())
					std::cout << "number of values on the stack: " << stack_main.getElementCount() << std::endl;
				else
					std::cout << "stack is empty, add elements in stack" << std::endl;
				break;
			case 4:
				if (stack_main.empty())
					std::cout << "stack is empty" << std::endl;
				else
					std::cout << "stack is not empty" << std::endl;
				break;
			case 5:
				if (stack_main.full())
					std::cout << "stack full" << std::endl;
				else
					std::cout << "stack is not full" << std::endl;
				break;
			case 6:
				if (!stack_main.empty())
					stack_main.clear();
				else
					std::cout << "stack is empty, add elements in stack" << std::endl;
				break;
			case 7:
				if (!stack_main.empty())
					std::cout << "stack top: " << stack_main.head() << std::endl;
				else
					std::cout << "stack is empty, add elements in stack" << std::endl;
				break;
			case 8:
				stack_main.show();
				break;
			case 9:
				stack_main.fileWrite("../../Files/stack.txt");
				break;
			case 10:
				stack_main.fileRead("../../Files/stack.txt");
				break;
			case 0:
				std::cout << "complete programm" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		system("pause");
	} while (choise);
}
// меню функций очереди
void _menu_queue_functions()
{
	char value = '\0';

	int choise = 0;

	const size_t size = 8;
	const size_t length = 75;

	queue<char, 10> queue_main;

	std::string menu_options[size] = \
	{
		"1. checking the queue for emptiness",
		"2. checking the queue for filling",
		"3. add element to queue",
		"4. dequeue element",
		"5. displaying queue elements",
		"6. writing data to a file",
		"7. reading data from a file",
		"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		std::cout << "select menu item: ";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
			case 1:
				if (queue_main.isEmpty())
					std::cout << "queue is empty" << std::endl;
				else
					std::cout << "items in the queue" << std::endl;
				break;
			case 2:
				if (queue_main.isFull())
					std::cout << "queue is full" << std::endl;
				else
					std::cout << "queue is not full" << std::endl;
				break;
			case 3:
				std::cout << "enter value: ";
				std::cin >> value;
				queue_main.enqueue(value);
				break;
			case 4:
				queue_main.dequeue();
				break;
			case 5:
				queue_main.show();
				break;
			case 6:
				queue_main.fileWrite("../../Files/queue.txt");
				break;
			case 7:
				queue_main.fileRead("../../Files/queue.txt");
				break;
			case 0:
				std::cout << "complete programm" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		system("pause");
	} while (choise);
}
// меню функций очереди с приоритетом
void _menu_queue_with_priority_functions()
{
	int choise = 0;
	int priority = 0;
	double value = 0;

	const size_t size = 8;
	const size_t length = 75;

	queuePriority<double, 10> queue_with_priority;

	std::string menu_options[size] = \
	{
		"1. checking the queue for emptiness",
		"2. checking the queue for filling",
		"3. add element with priority to queue",
		"4. removing the highest priority element from the queue",
		"5. displaying queue elements",
		"6. writing data to a file",
		"7. reading data from a file",
		"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		std::cout << "select menu item: ";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			if (queue_with_priority.isEmpty())
				std::cout << "queue is empty" << std::endl;
			else
				std::cout << "items in the queue" << std::endl;
			break;
		case 2:
			if (queue_with_priority.isFull())
				std::cout << "queue is full" << std::endl;
			else
				std::cout << "queue is not full" << std::endl;
			break;
		case 3:
			std::cout << "enter value: ";
			std::cin >> value;
			std::cout << "enter the priority of the element to be added: ";
			std::cin >> priority;
			queue_with_priority.insertWithPriority(value, priority);
			break;
		case 4:
			queue_with_priority.pullHighestPriorityElement();
			break;
		case 5:
			queue_with_priority.show();
			break;
		case 6:
			queue_with_priority.fileWrite("../../Files/queue_priority.txt");
			break;
		case 7:
			queue_with_priority.fileRead("../../Files/queue_priority.txt");
			break;
		case 0:
			std::cout << "complete programm" << std::endl;
			break;
		default:
			std::cout << "select the correct menu item" << std::endl;
			break;
		}
		system("pause");
	} while (choise);
}
// общее меню
void start()
{
	short choise = 0;
	short selection = 0;

	const size_t size = 6;
	const size_t length = 75;

	std::string menu_options[size] = \
	{
		"1. Template functions",
		"2. TemplateClass array",
		"3. TemplateClass stack",
		"4. TemplateClass queue",
		"5. TemplateClass priority queue",
		"0. EXIT"
	};

	do
	{
		system("cls");
		// ************************** //
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		//
		std::cout << '|';
		for (size_t i = 0; i < (length - strlen("MENU")) / 2; ++i)
			std::cout << ' ';
		std::cout << "MENU";
		for (size_t i = 0; i < (length - strlen("MENU")) / 2 + 1; ++i)
			std::cout << ' ';
		std::cout << '|' << std::endl;
		//
		std::cout << '+';
		for (size_t i = 0; i < length; ++i)
			std::cout << '-';
		std::cout << '+' << std::endl;
		// ************************** //
		for (size_t i = 0; i < size; ++i)
		{
			// ********************** //
			std::cout << '|' << menu_options[i];
			for (size_t j = 0; j < length - menu_options[i].length(); ++j)
				std::cout << ' ';
			std::cout << '|' << std::endl;
			//
			std::cout << '+';
			for (size_t i = 0; i < length; ++i)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}
		// ************************** //	
		std::cout << "choose menu item: ";
		std::cin >> choise;
		switch (choise)
		{
			case 1:
				system("cls");
				_menu_template_functions();
				break;
			case 2:
				system("cls");
				_menu_array_functions();
				break;
			case 3:
				system("cls");
				_menu_stack_functions();
				break;
			case 4:
				system("cls");
				_menu_queue_functions();
				break;
			case 5:
				system("cls");
				_menu_queue_with_priority_functions();
				break;
			case 0:
				std::cout << "complete programm" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
			}
		} while (choise);
}
