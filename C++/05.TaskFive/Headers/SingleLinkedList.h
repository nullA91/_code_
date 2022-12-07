#pragma once

/*
Создайте шаблонный класс односвязного списка для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами :
	■ AddToHead – добавление элемента в голову;
	■ AddToTail – добавление элемента в хвост;
	■ DeleteFromHead – удаление элемента из головы;
	■ DeleteFromTail – удаление элемента из хвоста;
	■ DeleteAll – удаление всех элементов;
	■ Show – отображение всех элементов списка на экран;
	■ AddToPos - вставка элемента в заданную позицию; 
	■ DelToPos - удаление элемента по заданной позиции;
	■ SearchElemPos - поиск заданного элемента(функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи);
	■ SearchAndReplaceElem - поиск и замена заданного элемента(функция возвращает количество замененных элементов в случае успеха или -1 в случае неудачи);
    ■ Swap - переворот списка
*/

#include "Functions.h"
#include "Libraries.h"

template <typename type_d>
struct list_element
{
	type_d value;
	list_element* ptr_next_elem;
	// конструктор с одним параметром
	list_element(const type_d& _value) : value(_value), ptr_next_elem(nullptr) { }
};

template <typename type_d>
class singleLinkedList
{
	private:
		list_element<type_d>* begin;
		list_element<type_d>* end;

		unsigned int element_count;
	public:
		// конструктор без параметров
		singleLinkedList() : begin(nullptr), end(nullptr), element_count(NULL) { }
		// конструктор с одним параметром
		singleLinkedList(const type_d& value) : begin(value), end(value), element_count(1) { }
		// конструктор копирования
		singleLinkedList(const singleLinkedList<type_d>& list) 
		{
			list_element<type_d>* root = nullptr;

			if (list.element_count == 0)
			{
				std::cout << "list is empty add items to list" << std::endl;
				return;
			}

			root = list.begin;
			while (root) 
			{
				this->addToTail(root->value);
				root = root->ptr_next_elem;
			} element_count = list.element_count;
		}
		// деструктор
		~singleLinkedList()
		{
			list_element<type_d>* root = nullptr;

			if (element_count) 
			{
				root = begin;
				while (root) 
				{
					root = root->ptr_next_elem;
					delete begin;
					begin = root;
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
		bool addToPos(const type_d& value, const unsigned int& index);
		// удаление элемента из начала односвязного списка
		bool delFromHead();
		// удаление элемента из конца списка
		bool delFromTail();
		// удаление элемента по заданной позиции
		bool delToPos(const unsigned int& index);
		// удаление всех элементов
		bool delAll();
		// поиск заданного элемента
		int searchElemPos(const type_d& value);
		// поиск и замена заданного элемента
		int searchAndReplaceElem(const type_d& val_sorce, const type_d& val_replace);
		// переворот списка
		bool swap();
		// вывод элементов односвязного списка
		void show();
};

// добавление элемента в начало
template<typename type_d>
bool singleLinkedList<type_d>::addToHead(const type_d& value)
{
	list_element<type_d>* new_element = new list_element<type_d>(value);

	if (!element_count)
	{
		begin = new_element;
		end = new_element;
		++element_count;
		return true;
	}
	else
	{
		new_element->ptr_next_elem = begin;
		begin = new_element;
		++element_count;
		return true;
	}
	return false;
}
// добавление элемента в конец
template<typename type_d>
bool singleLinkedList<type_d>::addToTail(const type_d& value)
{
	list_element<type_d>* new_element = new list_element<type_d>(value);

	if (!element_count)
	{
		begin = new_element;
		end = new_element;
		++element_count;
		return true;
	}
	else
	{
		end->ptr_next_elem = new_element;
		end = new_element;
		++element_count;
		return true;
	}
	return false;
}
// добавление элемента в заданную позицию
template<typename type_d>
bool singleLinkedList<type_d>::addToPos(const type_d& value, const unsigned int& index)
{
	list_element<type_d>* new_element = nullptr;
	list_element<type_d>* root = nullptr;

	unsigned int step = 2;

	if (index > (element_count + 1) || index <= 0)
	{
		std::cout << "target item serial number exceeds list size, please enter correct target item serial number" << std::endl;
		return false;
	}
	else
	{
		if (index == 1)
			this->addToHead(value);
		else if (index > element_count)
			this->addToTail(value);
		else
		{
			new_element = new list_element<type_d>(value);
			root = begin;
			while (step != index)
			{
				root = root->ptr_next_elem;
				++step;
			}
			new_element->ptr_next_elem = root->ptr_next_elem;
			root->ptr_next_elem = new_element;

			++element_count;
		}
		return true;
	}
}
// удаление элемента из начала односвязного списка
template<typename type_d>
bool singleLinkedList<type_d>::delFromHead()
{
	list_element<type_d>* root = nullptr;

	if (element_count)
	{
		root = begin;
		begin = begin->ptr_next_elem;
		--element_count;
		delete root;
		return true;
	}

	std::cout << "list is empty add items to list" << std::endl;
	return false;
}
// удаление элемента из конца списка
template<typename type_d>
bool singleLinkedList<type_d>::delFromTail()
{
	list_element<type_d>* root = nullptr;

	if (element_count)
	{
		root = begin;
		while (root)
		{
			if (root->ptr_next_elem == end)
			{
				end = root;
				end->ptr_next_elem = nullptr;
				delete root->ptr_next_elem;
				break;
			}
			else if (root == end)
			{
				delete end;
				begin = end = nullptr;
				break;
			}
			root = root->ptr_next_elem;
		}
		--element_count;
		return true;
	}

	std::cout << "list is empty add items to list" << std::endl;
	return false;
}
// удаление всех элементов
template<typename type_d>
bool singleLinkedList<type_d>::delAll()
{
	list_element<type_d>* root = nullptr;

	if (element_count)
	{
		root = begin;
		while (root)
		{
			root = begin->ptr_next_elem;
			delete begin;
			begin = root;
		}
		element_count = 0;
	}
	else
	{
		std::cout << "list is empty add items to list" << std::endl;
		return false;
	}
}
// удаление элемента по заданной позиции
template<typename type_d>
bool singleLinkedList<type_d>::delToPos(const unsigned int& index)
{
	list_element<type_d>* root = nullptr;
	list_element<type_d>* element = nullptr;

	unsigned int step = 2;

	if (index > element_count || index <= 0)
	{
		std::cout << "target item serial number exceeds list size, please enter correct target item serial number" << std::endl;
		return false;
	}
	else
	{
		if (element_count)
		{
			if (index == 1)
				this->delFromHead();
			else if (index == element_count)
				this->delFromTail();
			else
			{
				root = begin;
				while (step != index)
				{
					root = root->ptr_next_elem;
					++step;
				}

				element = root->ptr_next_elem;
				root->ptr_next_elem = root->ptr_next_elem->ptr_next_elem;
				delete element;
			}
			--element_count;
			return true;
		}

		std::cout << "list is empty add items to list" << std::endl;
		return false;
	}
}
// поиск заданного элемента
template<typename type_d>
int singleLinkedList<type_d>::searchElemPos(const type_d& value)
{
	unsigned int position = 1;

	list_element<type_d>* root = nullptr;

	if (!element_count)
	{
		std::cout << "list is empty add items to list" << std::endl;
		return -1;
	}
	else
	{
		root = begin;

		while (root)
		{
			if (root->value == value)
				return position;
			++position;
			root = root->ptr_next_elem;
		}
	} return NULL;
}
// поиск и замена заданного элемента
template<typename type_d>
int singleLinkedList<type_d>::searchAndReplaceElem(const type_d& val_sorce, const type_d& val_replace)
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
bool singleLinkedList<type_d>::swap()
{
	bool execution = false;

	list_element<type_d>* root = nullptr;

	singleLinkedList<type_d> new_list;

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
		root = begin;
		while (root)
		{
			new_list.addToHead(root->value);
			root = root->ptr_next_elem;
		}

		this->delAll();
		root = new_list.begin;
		while (root)
		{
			this->addToTail(root->value);
			root = root->ptr_next_elem;
		}

		return true;
	}
}
// вывод элементов односвязного списка
template<typename type_d>
void singleLinkedList<type_d>::show()
{
	list_element<type_d>* root = nullptr;

	bool execution = false;
	bool type = false;

	char symbol = '*';

	unsigned int columns = 0;
	unsigned int counter = 0;

	execution = element_count;
	if (execution)
	{
		system("cls");

		root = begin;
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
			root = begin;
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
			root = begin;
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
			root = begin;
			for (size_t i = 0; i < element_count; ++i)
			{
				columns = valueLength(root->value) + 2;
				std::cout << '+';
				for (size_t j = 0; j < columns; ++j)
					std::cout << '-';
				std::cout << '+' << ' ';
				root = root->ptr_next_elem;
			} std::cout << symbol << '\n';

			root = begin;
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
			root = begin;
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
/*
{
	bool execution = false;

	list_element<type_d>* root = nullptr;
	
	singleLinkedList<type_d> new_list;

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
		root = begin;
		
		while (root)
		{
			if (execution == false)
			{
				new_list.addToTail(root->value);
				execution = true;
			}
			else
				new_list.addToHead(root->value);
			root = root->ptr_next_elem;
		}

		this->delAll();
		root = new_list.begin;
		while (root)
		{
			this->addToTail(root->value);
			root = root->ptr_next_elem;
		}
		
		return true;
	}
}
*/