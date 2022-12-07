#pragma once

/*
Создайте шаблонный класс двусвязного списка для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами:
	■ AddToHead – добавление элемента в голову;
	■ AddToTail – добавление элемента в хвост;
	■ DeleteFromHead – удаление элемента из головы;
	■ DeleteFromTail – удаление элемента из хвоста;
	■ DeleteAll – удаление всех элементов;
	■ Show – отображение всех элементов списка на экран.
	■ SearchElemPos - вставка элемента в заданную позицию;
	■ DelToPos - удаление элемента по заданной позиции;
	■ SearchElemPos - поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи);
	■ SearchAndReplaceElem - поиск и замена заданного элемента (функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи);
	■ Swap - переворот списка;
*/

#include "Functions.h"
#include "Libraries.h"

template <typename type_d>
struct element
{
	type_d value;
	element* ptr_next_elem;
	element* ptr_prev_elem;
	// конструктор с одним параметром
	element(const type_d& _value) : value(_value), ptr_next_elem(nullptr), ptr_prev_elem(nullptr) { }
};

template <typename type_d>
class doublyLinkedList
{
private:
	element<type_d>* head;
	element<type_d>* tail;

	unsigned int element_count;
public:
	// конструктор без параметров
	doublyLinkedList() : head(nullptr), tail(nullptr), element_count(NULL) { }
	// конструктор с одним параметром
	doublyLinkedList(const type_d& value)
	{
		
		element<type_d>* new_element = new element<type_d>(value);

		head = new_element;
		tail = new_element;

		head->ptr_prev_elem = tail;
		tail->ptr_next_elem = head;

		element_count = 1;
	}
	
	// конструктор копирования
	doublyLinkedList(const doublyLinkedList<type_d>& list)
	{
		element<type_d>* root = nullptr;

		if (list.element_count == 0)
		{
			std::cout << "list is empty add items to list" << std::endl;
			return;
		}

		root = list.head;
		while (root)
		{
			this->addToTail(root->value);
			root = root->ptr_next_elem;
		} element_count = list.element_count;
	}
	
	// деструктор
	~doublyLinkedList()
	{
		element<type_d>* root = nullptr;
		int counter = element_count;

		if (element_count)
		{
			root = head;
			while (counter)
			{
				root = root->ptr_next_elem;
				delete head;
				head = root;
				--counter;
			}
		}
	}
	// ************************************* //
	// ************** МЕТОДЫ *************** //
	// ************************************* //
	// добавление элемента в начало
	bool addToHead(const type_d& value);
	// добавление элемента в конец
	bool addToTail(const type_d& value);
	// добавление элемента в заданную позицию
	bool addToPos(const type_d& value, const unsigned int& position);
	// удаление элемента из начала односвязного списка
	bool delFromHead();
	// удаление элемента из конца списка
	bool delFromTail();
	// удаление элемента по заданной позиции
	bool delToPos(const unsigned int& position);
	// удаление всех элементов
	bool delAll();
	// поиск заданного элемента
	int searchElemPos(const type_d& value);
	// поиск и замена заданного элемента
	int searchAndReplaceElem(const type_d& val_sorce, const type_d& val_replace);
	// переворот списка
	bool swap();
	// вывод элементов двусвязного списка
	void show();
};

// добавление элемента в начало
template<typename type_d>
bool doublyLinkedList<type_d>::addToHead(const type_d& value)
{
	element<type_d>* new_element = new element<type_d>(value);

	if (!element_count)
	{
		head = new_element;
		tail = new_element;

		head->ptr_prev_elem = tail;
		tail->ptr_next_elem = head;

		++element_count;
		return true;
	}
	else
	{
		new_element->ptr_next_elem = head;
		new_element->ptr_prev_elem = tail;
		head->ptr_prev_elem = new_element;
		head = new_element;
		tail->ptr_next_elem = head;

		++element_count;
		return true;
	}
	return false;
}
// добавление элемента в конец
template<typename type_d>
bool doublyLinkedList<type_d>::addToTail(const type_d& value)
{
	element<type_d>* new_element = new element<type_d>(value);

	if (!element_count)
	{
		head = new_element;
		tail = new_element;

		head->ptr_prev_elem = tail;
		tail->ptr_next_elem = head;

		++element_count;
		return true;
	}
	else
	{
		new_element->ptr_prev_elem = tail;
		new_element->ptr_next_elem = head;
		tail->ptr_next_elem = new_element;
		tail = new_element;
		head->ptr_prev_elem = tail;

		++element_count;
		return true;
	}
	return false;
}
// добавление элемента в заданную позицию
template<typename type_d>
bool doublyLinkedList<type_d>::addToPos(const type_d& value, const unsigned int& position)
{
	bool pass = false;

	element<type_d>* new_element = nullptr;
	element<type_d>* root = nullptr;

	unsigned int index = 0;

	if (position > (element_count + 1) || position <= 0)
	{
		std::cout << "target item serial number exceeds list size, please enter correct target item serial number" << std::endl;
		return false;
	}
	else
	{
		if (position == 1)
		{
			this->addToHead(value);
			return true;
		}
		else if (position > element_count)
		{
			addToTail(value);
			return true;
		}

		new_element = new element<type_d>(value);

		if (position <= (element_count / 2))
		{
			root = head;
			pass = true;
		} else root = tail;
		
		if (pass)
		{
			index = position;
			while (--index)
				root = root->ptr_next_elem;
		}
		else
		{
			index = element_count - position;
			while (index--)
				root = root->ptr_prev_elem;
		}

		new_element->ptr_next_elem = root;
		new_element->ptr_prev_elem = root->ptr_prev_elem;
		root->ptr_prev_elem->ptr_next_elem = new_element;
		root->ptr_prev_elem = new_element;

		++element_count;
		return true;
	}
}
// удаление элемента из начала односвязного списка
template<typename type_d>
bool doublyLinkedList<type_d>::delFromHead()
{
	element<type_d>* root = nullptr;

	if (element_count)
	{
		root = head;
		head = head->ptr_next_elem;
		head->ptr_prev_elem = tail;
		tail->ptr_next_elem = head;
		--element_count;
		delete root;
		return true;
	}

	std::cout << "list is empty add items to list" << std::endl;
	return false;
}
// удаление элемента из конца списка
template<typename type_d>
bool doublyLinkedList<type_d>::delFromTail()
{
	element<type_d>* end = nullptr;

	if (element_count)
	{
		end = tail;
		tail = tail->ptr_prev_elem;
		head->ptr_prev_elem = tail;
		tail->ptr_next_elem = head;
		delete end;
		--element_count;
		return true;
	}

	std::cout << "list is empty add items to list" << std::endl;
	return false;
}
// удаление всех элементов
template<typename type_d>
bool doublyLinkedList<type_d>::delAll()
{
	element<type_d>* root = nullptr;

	if (element_count)
	{
		root = head;
		while (element_count)
		{
			root = head->ptr_next_elem;
			delete head;
			head = root;
			--element_count;
		}
	}
	else
	{
		std::cout << "list is empty add items to list" << std::endl;
		return false;
	}
}
// удаление элемента по заданной позиции
template<typename type_d>
bool doublyLinkedList<type_d>::delToPos(const unsigned int& position)
{
	bool pass = false;

	element<type_d>* root = nullptr;
	element<type_d>* _element = nullptr;

	unsigned int index = 0;

	if (position > element_count || position <= 0)
	{
		std::cout << "target item serial number exceeds list size, please enter correct target item serial number" << std::endl;
		return false;
	}
	else
	{
		if (element_count)
		{
			if (position == 1)
				delFromHead();
			else if (position == element_count)
				delFromTail();
			else
			{
				if (position <= (element_count / 2))
				{
					root = head;
					pass = true;
				}
				else root = tail;

				if (pass)
				{
					index = position;
					while (--index)
						root = root->ptr_next_elem;
				}
				else
				{
					index = element_count - position;
					while (index--)
						root = root->ptr_prev_elem;
				}

				_element = root;
				root->ptr_prev_elem->ptr_next_elem = root->ptr_next_elem;
				root->ptr_next_elem->ptr_prev_elem = root->ptr_prev_elem;
				delete _element;
				--element_count;
			}
			return true;
		}

		std::cout << "list is empty add items to list" << std::endl;
		return false;
	}
}

// поиск заданного элемента
template<typename type_d>
int doublyLinkedList<type_d>::searchElemPos(const type_d& value)
{
	unsigned int position = 1;
	unsigned int counter = 0;

	element<type_d>* root = nullptr;

	if (!element_count)
	{
		std::cout << "list is empty add items to list" << std::endl;
		return -1;
	}
	else
	{
		root = head;
		counter = element_count;

		while (counter)
		{
			if (root->value == value)
				return position;
			++position;
			--counter;
			root = root->ptr_next_elem;
		}
	} return NULL;
}
// поиск и замена заданного элемента
template<typename type_d>
int doublyLinkedList<type_d>::searchAndReplaceElem(const type_d& val_sorce, const type_d& val_replace)
{
	unsigned int counter_replaced_element = 0;
	unsigned int position = 0;

	if (!element_count)
	{
		std::cout << "list is empty add items to list" << std::endl;
		return -1;
	}

	while (position = this->searchElemPos(val_sorce))
	{
		++counter_replaced_element;
		if (position < element_count)
		{
			this->delToPos(position);
			this->addToPos(val_replace, position);
		}
		else
		{
			this->delFromTail();
			this->addToTail(val_replace);
		}
	} if (counter_replaced_element) return counter_replaced_element;

	return -1;
}
// переворот списка
template<typename type_d>
bool doublyLinkedList<type_d>::swap()
{
	bool execution = false;

	unsigned int counter = 0;

	element<type_d>* root = nullptr;

	doublyLinkedList<type_d> new_list;

	if (element_count == 0)
	{
		std::cout << "list is empty add items to list" << std::endl;
		return false;
	}
	else if (element_count == 1)
	{
		std::cout << "list has one element, add elements to the list" << std::endl;
		return false;
	}
	else
	{
		root = head;
		counter = element_count;
		while (counter)
		{
			new_list.addToHead(root->value);
			root = root->ptr_next_elem;
			--counter;
		}

		delAll();
		root = new_list.head;
		counter = new_list.element_count;
		while (counter)
		{
			addToTail(root->value);
			root = root->ptr_next_elem;
			--counter;
		}

		return true;
	}
}
// вывод элементов двусвязного списка
template<typename type_d>
void doublyLinkedList<type_d>::show()
{
	element<type_d>* root = nullptr;

	bool execution = false;
	bool type = false;

	char symbol = '^';

	unsigned int columns = 0;
	unsigned int counter = 0;

	execution = element_count;
	if (execution)
	{
		system("cls");

		root = head;
		type = valueDataType(root->value);
		if (type)
		{
			std::cout << symbol;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				std::cout << symbol;
				for (size_t j = 0; j < columns; ++j)
					std::cout << symbol;
				std::cout << symbol << symbol;
				root = root->ptr_next_elem;
			} std::cout << symbol << symbol << '\n';
			// верх строки
			std::cout << symbol << ' ';
			root = head;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				std::cout << '+';
				for (size_t j = 0; j < columns; ++j)
					std::cout << '-';
				std::cout << '+' << ' ';
				root = root->ptr_next_elem;
			} std::cout << symbol << '\n';
			// середина строки
			std::cout << symbol << ' ';
			root = head;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				counter = (columns - valueLength(root->value)) / 2;

				std::cout << '|';
				for (size_t j = 0; j < counter; ++j)
					std::cout << ' ';
				std::cout << root->value;
				for (size_t j = 0; j < counter; ++j)
					std::cout << ' ';
				if ((columns - valueLength(root->value)) % 2 != 0)
					std::cout << ' ';
				std::cout << '|' << ' ';
				root = root->ptr_next_elem;
			} std::cout << symbol << '\n';
			// низ
			std::cout << symbol << ' ';
			root = head;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				std::cout << '+';
				for (size_t j = 0; j < columns; ++j)
					std::cout << '-';
				std::cout << '+' << ' ';
				root = root->ptr_next_elem;
			} std::cout << symbol << '\n';

			root = head;
			std::cout << symbol;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				std::cout << symbol;
				for (size_t j = 0; j < columns; ++j)
					std::cout << symbol;
				std::cout << symbol << symbol;
				root = root->ptr_next_elem;
			} std::cout << symbol << symbol << '\n';
		}
		// пользовательский тип данных
		else
		{
			root = head;
			for (size_t i = 0; i < element_count; ++i)
			{
				std::cout << root->value << std::endl;
				root = root->ptr_next_elem;
			}
		}
	}
	else std::cout << "list is empty, add elements there" << std::endl;
	system("pause");
}