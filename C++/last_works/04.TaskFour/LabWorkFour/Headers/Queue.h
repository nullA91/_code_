#pragma once

#include "../Headers/Functions.h"
#include "../Headers/Libraries.h"

/*
Задание №3
Создайте шаблонный класс обычной очереди для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами:
■ IsEmpty – проверка очереди на пустоту
■ IsFull – проверка очереди на заполнение
■ Enqueue – добавление элемента в очередь
■ Dequeue – удаление элемента из очереди
■ Show – отображение всех элементов очереди на экран
*/

template<typename data_type, unsigned int size = 0>
class queue
{
private:
	data_type* FRONT;
	data_type* REAR;
	data_type* elements;
	unsigned int element_count;
public:

	// ************************************* //
	// ***** КОНСТРУКТОРЫ И ДЕСТРУКТОР ***** //
	// ************************************* //

	// конструктор без параметров
	queue() : FRONT(nullptr), REAR(nullptr), element_count(0)
	{
		if (size > 0)
			elements = new data_type[size];
		else
			elements = nullptr;
	}
	// конструктор копирования
	queue(const queue& queue_copy)
	{
		if (queue_copy.element_count)
		{
			if (elements != nullptr)
			{
				element_count = queue_copy.element_count;
				for (size_t i = 0; i < queue_copy.element_count; ++i)
					elements[i] = queue_copy.elements[i];
				FRONT = elements[0];
				REAR = elements[element_count - 1];
			}
			else
				std::cout << "ERROR, no memory allocated for current object, allocate memory for current object" << std::endl;
		}
		else
			std::cout << "there is no data in the copied queue, add data to the queue" << std::endl;
	}
	// деструктор
	~queue()
	{
		if (elements != nullptr)
			delete[] elements;
	}

	// ************************************* //
	// ************** МЕТОДЫ *************** //
	// ************************************* //

	// добавление элемента в очередь
	void enqueue(data_type value)
	{
		if (isEmpty())
		{
			elements[0] = value;
			FRONT = &elements[0];
			REAR = &elements[0];
			element_count = 1;
		}
		else
		{
			if (!isFull())
			{
				elements[element_count] = value;
				REAR = &elements[element_count];
				++element_count;
			}
			else
				std::cout << "the queue is full, remove the element from the queue" << std::endl;
		}
	}
	// удаление элемента из очереди
	void dequeue()
	{
		if (!isEmpty())
		{
			--element_count;

			if (element_count)
				++FRONT;
			else
			{
				FRONT = nullptr;
				REAR = nullptr;
			}
		}
		else
			std::cout << "queue is empty, add elements there" << std::endl;
	}
	// вывод элементов очереди
	void show()
	{
		bool execution = false;
		bool type = false;

		unsigned int columns = 0;
		unsigned int counter = 0;

		execution = element_count;
		if (execution)
		{
			system("cls");

			type = valueDataType(elements[0]);
			if (type)
			{
				// *********** //
				// ** ВЫВОД ** //
				// *********** //
				// верх строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(elements[i]) + 2;
					std::cout << '+';
					for (size_t j = 0; j < columns; ++j)
						std::cout << '-';
					std::cout << '+' << ' ';
				} std::cout << '\n';
				// середина строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(elements[i]) + 2;
					counter = (columns - valueLength(elements[i])) / 2;

					std::cout << '|';
					for (size_t j = 0; j < counter; ++j)
						std::cout << ' ';
					std::cout << elements[i];
					for (size_t j = 0; j < counter; ++j)
						std::cout << ' ';
					if ((columns - valueLength(elements[i])) % 2 != 0)
						std::cout << ' ';
					std::cout << '|' << ' ';
				} std::cout << '\n';
				// низ строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(elements[i]) + 2;
					std::cout << '+';
					for (size_t j = 0; j < columns; ++j)
						std::cout << '-';
					std::cout << '+' << ' ';
				} std::cout << '\n';
			}
			// пользовательский тип данных
			else
			{
				for (size_t i = 0; i < element_count; ++i)
					std::cout << elements[i] << std::endl;
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

	// запись данных в файл
	bool fileWrite(const std::string& path)
	{
		std::ofstream file;

		file.open(path.c_str(), std::ios_base::app);

		if (file.is_open())
		{
			bool execution = false;
			bool type = false;

			unsigned int columns = 0;
			unsigned int counter = 0;

			execution = element_count;
			if (execution)
			{
				type = valueDataType(elements[0]);
				if (type)
				{
					// верх строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(elements[i]) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
						file << '+' << ' ';
					} file << '\n';
					// середина строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(elements[i]) + 2;
						counter = (columns - valueLength(elements[i])) / 2;

						file << '|';
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						file << elements[i];
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						if ((columns - valueLength(elements[i])) % 2 != 0)
							file << ' ';
						file << '|' << ' ';
					} file << '\n';
					// низ строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(elements[i]) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
						file << '+' << ' ';
					} file << '\n';
				}
				// пользовательский тип данных
				else
				{
					for (size_t i = 0; i < element_count; ++i)
						file << elements[i] << '\n';
				}
			}
			else file << "queue is empty, add elements there" << '\n';
		}
		else
		{
			std::cout << "error opening file" << std::endl;
			return false;
		}
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