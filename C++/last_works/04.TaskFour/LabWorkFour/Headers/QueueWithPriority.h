#pragma once

#include "../Headers/Libraries.h"
#include "../Headers/Functions.h"

/*
Задание №4
Создайте класс очереди с приоритетами для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами очереди:
■ IsEmpty – проверка очереди на пустоту
■ IsFull – проверка очереди на заполнение
■ InsertWithPriority – добавление элемента c приоритетом в очередь
■ PullHighestPriorityElement – удаление элемента с самым высоким приоритетом из очереди
■ Peek – возврат самого большого по приоритету элемента. Обращаем ваше внимание, что элемент не удаляется из очереди.
■ Show – отображение всех элементов очереди на экран. При показе элемента также необходимо отображать приоритет.
*/
#define default_precedence 3
// структура данных содержащая элемент и метаданные(информацию) о нём
template <typename data_type>
struct element
{
public:
	// приоритет элемента
	unsigned int priority;
	// значение элемента
	data_type value;
	// указатель на следующий элемент
	element<data_type>* ptr_next_elem;
	// указатель на предыдущий элемент
	element<data_type>* ptr_prev_elem;
	// конструктор с параметрами - задает значение и приоритет элементу данных
	element(const data_type& value, unsigned int priority = default_precedence)
	{
		ptr_next_elem = nullptr;
		ptr_prev_elem = nullptr;
		this->value = value;
		this->priority = priority;
	}
};
// шаблонный класс очередь с приоритетом
template <typename data_type, unsigned int size = 0>
class queuePriority
{
private:
	element<data_type>* head;
	element<data_type>* tail;
	unsigned int element_count;
public:
	// ************************************* //
	// ***** КОНСТРУКТОРЫ И ДЕСТРУКТОР ***** //
	// ************************************* //

	// конструктор без параметров
	queuePriority() : head(nullptr), tail(nullptr), element_count(0) {}
	// конструктор копирования
	queuePriority(const queuePriority& queue)
	{
		element<data_type>* rootCopyQueue = nullptr;

		if (queue.element_count)
		{
			rootCopyQueue = queue.head;
			while (rootCopyQueue)
			{
				insertWithPriority(rootCopyQueue->value, rootCopyQueue->priority);
				rootCopyQueue = rootCopyQueue->ptr_next_elem;
			}
		}
		else std::cout << "queue is empty, add elements there" << std::endl;
	}
	// деструктор
	~queuePriority()
	{
		element<data_type>* root = nullptr;

		if (!isEmpty())
		{
			while (root)
			{
				root = root->ptr_next_elem;
				delete root->ptr_prev_elem;
			}
		}
	}
	// ************************************* //
	// ************** МЕТОДЫ *************** //
	// ************************************* //
	// добавление элемента в очередь по приоритету
	void insertWithPriority(const data_type& value, unsigned int priority = default_precedence)
	{
		element<data_type>* new_elem = new element<data_type>(value, priority);
		element<data_type>* begin_queue = nullptr;
		element<data_type>* end_queue = nullptr;

		// если очередь пустая
		if (isEmpty())
		{
			head = new_elem;
			tail = new_elem;
			element_count = 1;
		}
		else // если в очереди есть хотя бы один элемент
		{
			if (priority > default_precedence)
			{
				begin_queue = head;
				// добавление в начало очереди
				if (head->priority < new_elem->priority)
				{
					head = new_elem;

					begin_queue->ptr_prev_elem = new_elem;
					new_elem->ptr_next_elem = begin_queue;
				}
				// добавление в соответствии с приоритетом
				else if (new_elem->priority <= head->priority)
				{
					while (begin_queue->ptr_next_elem != nullptr)
					{
						if (new_elem->priority <= begin_queue->ptr_next_elem->priority)
							begin_queue = begin_queue->ptr_next_elem;
						else
							break;
					}

					if (begin_queue->ptr_next_elem != nullptr)
					{
						new_elem->ptr_next_elem = begin_queue->ptr_next_elem;
						new_elem->ptr_prev_elem = begin_queue;
						begin_queue->ptr_next_elem->ptr_prev_elem = new_elem;
						begin_queue->ptr_next_elem = new_elem;
					}
					// добавление элемента в конец очереди
					else
					{
						begin_queue->ptr_next_elem = new_elem;
						new_elem->ptr_prev_elem = begin_queue;
						tail = new_elem;
					}
				}
			}
			else
			{
				// добавление элемента в конец очереди
				end_queue = tail;
				if (tail->priority >= new_elem->priority)
				{
					tail = new_elem;
					new_elem->ptr_prev_elem = end_queue;
					end_queue->ptr_next_elem = new_elem;
				}
				// добавление в соответствии с приоритетом
				else
				{
					while (end_queue->ptr_prev_elem != nullptr)
					{
						if (new_elem->priority > end_queue->ptr_prev_elem->priority)
							end_queue = end_queue->ptr_prev_elem;
						else
							break;
					}
					if (end_queue->ptr_prev_elem != nullptr)
					{
						end_queue->ptr_prev_elem->ptr_next_elem = new_elem;
						new_elem->ptr_prev_elem = end_queue->ptr_prev_elem;
						new_elem->ptr_next_elem = end_queue;
						end_queue->ptr_prev_elem = new_elem;
					}
					// добавление в начало очереди
					else
					{
						end_queue->ptr_prev_elem = new_elem;
						new_elem->ptr_next_elem = end_queue;
						head = new_elem;
					}
				}
			}
			++element_count;
		}
	}
	// удаление элемента с самым высоким приоритетом из очереди(удаление сначала очереди)
	void pullHighestPriorityElement()
	{
		if (!isEmpty())
		{
			element<data_type>* ptr_tmp = head;

			head = head->ptr_next_elem;
			--element_count;
			delete ptr_tmp;
			if (element_count == 0)
				tail = nullptr;
		}
		else std::cout << "queue is empty, add elements there" << std::endl;
	}
	// возврат самого большого по приоритету элемента
	data_type peek()
	{
		if (!isEmpty())
			return head->value;
		else std::cout << "queue is empty, add elements there" << std::endl;
	}
	// вывод элементов очереди
	void show()
	{
		element<data_type>* root = nullptr;

		bool execution = false;
		bool type = false;

		char symbol = '*';

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
		else std::cout << "queue is empty, add elements there" << std::endl;
	}
	// проверка очереди на пустоту
	bool isEmpty() { return (element_count == 0) ? true : false; }
	// проверка заполнена ли очередь
	bool isFull() { return (element_count == size) ? true : false; }
	// ************************************* //
	// ********* РАБОТА С ФАЙЛАМИ ********** //
	// ************************************* //
	// запись данный в файл
	bool fileWrite(const std::string& path)
	{
		element<data_type>* root = nullptr;

		std::ofstream file;

		file.open(path.c_str(), std::ios_base::app);

		if (file.is_open())
		{
			bool execution = false;
			bool type = false;

			unsigned int columns = 0;
			unsigned int counter = 0;

			root = head;
			execution = element_count;
			if (execution)
			{
				type = valueDataType(root->value);
				if (type)
				{
					// верх строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(root->value) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
						file << '+' << ' ';
						root = root->ptr_next_elem;
					} file << '\n';
					// середина строки
					root = head;
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(root->value) + 2;
						counter = (columns - valueLength(root->value)) / 2;

						file << '|';
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						file << root->value;
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						if ((columns - valueLength(root->value)) % 2 != 0)
							file << ' ';
						file << '|' << ' ';
						root = root->ptr_next_elem;
					} file << '\n';
					// низ строки
					root = head;
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(root->value) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
						file << '+' << ' ';
						root = root->ptr_next_elem;
					} file << '\n';
				}
				// пользовательский тип данных
				else
				{
					root = head;
					for (size_t i = 0; i < element_count; ++i)
					{
						file << root->value << '\n';
						root = root->ptr_next_elem;
					}
				}
			}
			else file << "queue is empty, add elements there" << '\n';
		}
		else
		{
			std::cout << "error opening file" << std::endl;
			return false;
		}
		return true;
	}
	// чтение данных из файла
	bool fileRead(const std::string& path)
	{
		const unsigned int length = 1024;

		std::ifstream file;
		char* string;

		file.open(path.c_str(), std::ios_base::in);

		if (file.is_open())
		{
			string = new char[length];

			while (file)
			{
				file.getline(string, length, '\n');
				std::cout << string << std::endl;
			}

			delete[] string;
			file.close();
			return true;
		}
		else
		{
			std::cout << "error opening file" << std::endl;
			return false;
		}
	}
};

/*
// удаление элемента с самым высоким приоритетом из очереди(удаление сначала очереди)
void pullHighestPriorityElement()
{
	if (!isEmpty())
	{
		element<data_type>* ptr_tmp = head;

		head = head->ptr_next_elem;
		--element_count;
		delete ptr_tmp;
		if (element_count == 0)
			tail = nullptr;
	}
	else std::cout << "queue is empty, add elements there" << std::endl;
}
*/

/*
// удаление элемента по приоритетоу из очереди
data_type pullHighestPriorityElement(const unsigned int& priority)
{
	element<data_type>* root = nullptr;
	data_type value;

	if (!isEmpty())
	{
		if (element_count > 1)
		{
			root = head;

			if (root->ptr_next_elem->priority == priority)
			{
				head = root->ptr_next_elem;
				head->ptr_prev_elem = nullptr;

				value = root->value;
				delete root;

				return value;
			}
			else root = root->ptr_next_elem;

			while (root)
			{
				if (root->priority == priority)
				{
					if (root->ptr_next_elem != nullptr)
					{
						value = root->value;

						root->ptr_next_elem->ptr_prev_elem = root->ptr_prev_elem;
						root->ptr_prev_elem->ptr_next_elem = root->ptr_next_elem;

						delete root;
						return value;
					}
					else
					{
						value = root->value;

						tail = root->ptr_prev_elem;
						tail->ptr_next_elem = nullptr;

						delete root;
						return value;
					}
				}
				root = root->ptr_next_elem;
			} if (root == nullptr) return false;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
	}
	else std::cout << "queue is empty, add elements there" << std::endl;
}
*/