#pragma once

#include "../Headers/TemplateFunctions.h"
#include "../Headers/Libraries.h"

/*
Задание №1
Создать шаблонный класс-контейнер Array, который представляет собой массив, позволяющий хранить объекты заданного типа.
Класс должен реализовывать следующие функции:
■ getSize – получение размера массива (количество элементов, под которые выделена память);
■ setSize(int size, int grow = 1) – установка размера массива (если параметр size больше предыдущего размера массива, то
выделяется дополнительный блок памяти, если нет, то «лишние» элементы теряются и память освобождается); параметр
grow определяет для какого количества элементов необходимо выделить память, если количество элементов превосходит
текущий размер массива. Например, SetSize(5, 5); означает, что при добавлении 6-го элемента размер массива становится
равным 10, при добавлении 11-го - 15 и т. д.;
■ getUpperBound - получение последнего допустимого индекса в массиве. Например, если при размере массива 10, вы добавляете в него 4 элемента, то функция вернет 3;
■ isEmpty - массив пуст?
■ freeExtra - удалить «лишнюю» память (выше последнего допустимого индекса);
■ removeAll – удалить все;
■ getAt -получение определенного элемента (по индексу);
■ setAt – установка нового значения для определенного элемента(по индексу)
■ operator [] – для реализации двух предыдущих функций;
■ add – добавление элемента в массив (при необходимости массив увеличивается на значение grow функции SetSize);
■ append – «сложение» двух массивов;
■ operator =;
■ getAddress – получения адреса массива с данными;
■ insertAt – вставка элемента(-ов) в заданную позицию;
■ removeAt – удаление элемента(-ов) с заданной позиции.
*/

template<typename data_type, size_t _size_ = 0>
class array
{
private:
	data_type* data;
	unsigned int size;
	unsigned int element_count;
public:
	
	// ##################################### //
	// ************************************* //
	// ***** конструкторы и деструктор ***** //
	// ************************************* //
	// ##################################### //
	
	// конструктор без параметров
	array() : data(nullptr), size(_size_), element_count(0) { if (size > 0) data = new data_type[size]; }
	// конструктор копирования
	array(const array& object)
	{
		size = object.size;
		data = new data_type[size];
		for (unsigned int i = 0; i < object.element_count; ++i)
			data[i] = object.data[i];
		element_count = object.element_count;
	}
	// деструктор
	~array() { if (data != nullptr) delete[] data; }
	
	// ############################ //
	// **************************** //
	// ********** методы ********** //
	// **************************** //
	// ############################ //

	// проверка массива на пустоту
	bool isEmpty() { return (element_count == 0) ? true : false; }
	// освобождение лишней памяти массива
	bool freeExtra()
	{
		if (!isEmpty())
		{
			data_type* temporary_facility = nullptr;

			if (element_count < size)
			{
				temporary_facility = new data_type[element_count];
				for (size_t i = 0; i < element_count; ++i)
					temporary_facility[i] = data[i];
				delete[] data;
				data = temporary_facility;
				return true;
			} 
			else
			{
				std::cout << "number of elements is equal to array size" << std::endl;
				return false;
			}
		} 
		else
		{
			std::cout << "array is empty, add elements to array" << std::endl;
			return false;
		}
	}
	// удаление всех элементов в массиве
	bool removeAll()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = new data_type[size];
			for (size_t i = 0; i < size; ++i)
				data[i] = 0;
			element_count = 0;
			return true;
		}
		else
		{
			std::cout << "array is empty, add elements to array" << std::endl;
			return false;
		}
	}
	// добавление элемента в конец массива
	bool add(const data_type& value)
	{
		if (element_count == size)
		{
			setSize(size + 1);
			data[element_count] = value;
			++element_count;
			return true;
		}
		else
		{
			data[element_count] = value;
			++element_count;
			return true;
		}
		return false;
	}
	// сложение двух массивов
	array<data_type> append(const array& object)
	{
		bool flag = (this->size > object.size) ? true : false;

		short index = 0;

		static size_t length = (this->size >= object.size) ? this->size : object.size;

		array<data_type> result;

		result.setSize(length);

		if (this->element_count > object.element_count)
		{
			index = 0;
			while (index < object.element_count)
			{
				result.setAt(data[index] + object.data[index], index);
				++index;
			} result.setElemCount(this->element_count);
			while (index < this->element_count)
			{
				result.setAt(data[index], index);
				++index;
			}
		}
		else if (this->element_count < object.element_count)
		{
			index = 0;
			while (index < this->element_count)
			{
				result.setAt(data[index] + object.data[index], index);
				++index;
			} result.setElemCount(object.element_count);
			while (index < object.element_count)
			{
				result.setAt(object.data[index], index);
				++index;
			}
		}
		else
		{
			for(size_t i = 0; i < element_count; ++i)
				result.setAt(data[i] + object.data[i], i);
			result.setElemCount(element_count);
		}
		return result;
	}
	// вставка элемента в заданную позицию
	bool insertAt(const data_type& value, const unsigned int& index)
	{
		data_type* temporary_facility = nullptr;

		if (isEmpty())
		{
			data = new data_type[1];
			data[0] = value;
			++element_count;
			return true;
		}
		else
		{
			temporary_facility = new data_type[element_count + 1];
			for (size_t i = 0; i < element_count; ++i)
			{
				if (i != index - 1)
					temporary_facility[i] = data[i];
				else
					temporary_facility[i] = value;
			}
			delete[] data;
			data = temporary_facility;
			++element_count;
			return true;
		}
		return false;
	}
	// удаление элемента с заданной позиции
	data_type removeAt(const unsigned int& index)
	{
		data_type value;
		data_type* temporary_facility = nullptr;

		if (!isEmpty())
		{
			--element_count;
			value = data[index - 1];
			if (element_count)
			{
				temporary_facility = new data_type[element_count];
				for (size_t i = 0, j = 0; i < element_count + 1; ++i)
				{
					if (i != index - 1)
					{
						temporary_facility[j] = data[i];
						++j;
					}
				}
				delete[]data;
				data = temporary_facility;
			}
		}
		else
		{
			std::cout << "array is empty, add elements to array" << std::endl;
			return false;
		}
		return value;
	}
	// инкрементирование элементов массива
	void incrementingArrayElements() { ++element_count; }
	// вывод элементов массива
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

			type = valueDataType(data[0]);
			if (type)
			{
				// верх строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(data[i]) + 2;
					std::cout << '+';
					for (size_t j = 0; j < columns; ++j)
						std::cout << '-';
				} std::cout << '+' << '\n';
				// середина строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(data[i]) + 2;
					counter = (columns - valueLength(data[i])) / 2;

					std::cout << '|';
					for (size_t j = 0; j < counter; ++j)
						std::cout << ' ';
					std::cout << data[i];
					for (size_t j = 0; j < counter; ++j)
						std::cout << ' ';
					if ((columns - valueLength(data[i])) % 2 != 0)
						std::cout << ' ';
				} std::cout << '|' << '\n';
				// низ строки
				for (size_t i = 0; i < element_count; ++i)
				{
					columns = valueLength(data[i]) + 2;
					std::cout << '+';
					for (size_t j = 0; j < columns; ++j)
						std::cout << '-';
				} std::cout << '+' << '\n';
			}
			// пользовательский тип данных
			else
			{
				for (size_t i = 0; i < element_count; ++i)
					std::cout << data[i] << std::endl;
			}
		}
		else std::cout << "array is empty, add elements there" << std::endl;
		system("pause");
	}

	// ############################ //
	// **************************** //
	// ***** работа с файлами ***** //
	// **************************** //
	// ############################ //

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
				type = valueDataType(data[0]);
				if (type)
				{
					// верх строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(data[i]) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
					} file << '+' << '\n';
					// середина строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(data[i]) + 2;
						counter = (columns - valueLength(data[i])) / 2;

						file << '|';
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						file << data[i];
						for (size_t j = 0; j < counter; ++j)
							file << ' ';
						if ((columns - valueLength(data[i])) % 2 != 0)
							file << ' ';
					} file << '|' << '\n';
					// низ строки
					for (size_t i = 0; i < element_count; ++i)
					{
						columns = valueLength(data[i]) + 2;
						file << '+';
						for (size_t j = 0; j < columns; ++j)
							file << '-';
					} file << '+' << '\n';
				}
				// пользовательский тип данных
				else
				{
					for (size_t i = 0; i < element_count; ++i)
						file << data[i] << std::endl;
				}
			}
			else std::cout << "array is empty, add elements there" << std::endl;

			file.close();
			return true;
		}
		else
		{
			std::cout << "error opening file" << std::endl;
			return false;
		}
	}
	// вывод данных из файла
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
	
	// ############################ //
	// **************************** //
	// *** перегрузка операторов ** //
	// **************************** //
	// ############################ //

	// перегрузка оператора индексации
	data_type& operator[](const unsigned int index) { return data[index]; }
	const data_type& operator[](const unsigned int index) const { return data[index]; }
	// перегрузка оператора присваивания
	array<data_type>& operator=(const array& object)
	{	
		data = new data_type[object.size];
		size = object.size;
		element_count = object.element_count;
		for (size_t i = 0; i < size; ++i)
			data[i] = object.data[i];
		
		return *this;
	}
	// перегрузка оператора <<
	friend std::ostream& operator<<(std::ostream& output, const array& object)
	{
		for (unsigned int i = 0; i < object.size; ++i)
			output << object.data[i];
		return  output;
	}
	// перегрузка оператора >>
	friend std::istream& operator >> (std::istream& input, const array& object)
	{
		data_type value;

		for (unsigned int i = 0; i < object.size; ++i)
		{
			input >> value;
			object.data[i] = value;
		}

		return input;
	}
	
	// ############################ //
	// **************************** //
	// ********* аксессоры ******** //
	// **************************** //
	// ############################ //

	// размер массива
	inline unsigned int getSize() const { return size; }
	// последний допустимый индекс массива
	inline unsigned int getUpperBound() const { return element_count - 1; }
	// получение определенногого элемента по индексу
	inline data_type getAt(const unsigned int& index) { return data[index]; }
	// получение адреса массива
	inline data_type* getArrayAddress() const { return data; }
	// получение количества элементов в массиве
	unsigned int getElementCount() const { return element_count; }
	
	// ############################ //
	// **************************** //
	// ********* мутаторы ********* //
	// **************************** //
	// ############################ //

	// установка размера массива
	inline void setSize(unsigned int size, unsigned int grow = 1)
	{
		data_type* temporary_facility = nullptr;

		// если массив пустой
		if (isEmpty())
		{
			if (data != nullptr) delete[] data;
			data = new data_type[size];
		}
		else
		{
			temporary_facility = new data_type[size];
			if (size <= element_count)
			{
				for (size_t i = 0; i < size; ++i)
					temporary_facility[i] = data[i];
			}
			else
			{
				for (size_t i = 0; i < element_count; ++i)
					temporary_facility[i] = data[i];
			}
			delete[] data;
			data = temporary_facility;
		}
		this->size = size;
	}
	// установка нового значения для определенного элемента
	inline void setAt(const data_type& value, const unsigned int& index) { data[index - 1] = value; }
	// установка количества элементов в массиве
	inline void setElemCount(const unsigned int& value) { element_count = value; }
};