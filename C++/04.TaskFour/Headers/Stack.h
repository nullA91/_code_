#pragma once

#include "../Headers/TemplateFunctions.h"
#include "../Headers/Libraries.h"

/*
Задание №2
Реализуйте шаблонный класс стека. Стек должен иметь фиксированный размер.
Также реализуйте набор операций для работы со стеком: 
	■ помещение символа в стек 
	■ выталкивание символа из стека
	■ подсчет количества символов в стеке 
	■ проверку пустой ли стек
	■ проверку полный ли стек 
	■ очистку стека
	■ получение без выталкивания верхнего символа в стеке.
*/

template<typename data_type, unsigned int _size_ = 0>
class stack
{
private:
	data_type* _stack_;
	int element_count;
	unsigned int size;
public:

	// ##################################### //
	// ************************************* //
	// ***** конструкторы и деструктор ***** //
	// ************************************* //
	// ##################################### //

	// конструктор без параметров
	stack() : _stack_(nullptr), element_count(0), size(_size_)
		{ if (size > 0) _stack_ = new data_type[size]; }
	// конструктор с параметрами
	stack(const unsigned int size)
	{
		this->size = size;
		_stack_ = new data_type[this->size];
		element_count = 0;
	}
	// конструктор копирования
	stack(const stack& object)
	{
		size = object.size;
		element_count = object.element_count;
		_stack_ = new data_type[size];

		if (!object.empty())
		{
			for (size_t i = 0; i < object.size; ++i)
				_stack_[i] = object._stack_[i];
		}
	}
	// деструктор
	~stack()
	{
		if (_stack_ != nullptr)
			delete[] _stack_;
	}
	
	// ############################ //
	// **************************** //
	// ********** методы ********** //
	// **************************** //
	// ############################ //
	
	// помещение элемента в стек
	void push(data_type value)
	{
		data_type* array_data = nullptr;

		if (element_count < size)
			_stack_[element_count] = value;
		else
		{
			array_data = new data_type[element_count];
			for (unsigned int i = 0; i < element_count; ++i)
				array_data[i] = _stack_[i];
			if (_stack_ != nullptr) delete[] _stack_;
			_stack_ = new data_type[++size];
			for (unsigned int i = 0; i < element_count; ++i)
				_stack_[i] = array_data[i];
			_stack_[element_count] = value;
			if (array_data != nullptr) delete[] array_data;
		}

		++element_count;
	}
	// получить последний элемент стека
	data_type pop() { return (element_count == 0) ? NULL : _stack_[--element_count]; }
	// значение последнего элемента(вершина) стека
	data_type head() const { return (element_count == 0) ? 0 : _stack_[element_count - 1]; }
	// очистка стека
	void clear()
	{
		if (_stack_ != nullptr) delete[] _stack_;
		_stack_ = new data_type[size];
		element_count = 0;
	}
	// проверка стека на пустоту
	bool empty() const { return (element_count == 0) ? true : false; }
	// проверка заполнен ли стек
	bool full() const { return (element_count == size) ? true : false; }
	// вывод элементов стека
	void show()
	{
		bool flag = true;
		bool setup = true;

		unsigned int columns = 0;
		unsigned int counter = 0;
		unsigned int index = 0;

		const char* type = nullptr;

		std::string value = "";

		index = element_count - 1;

		system("cls");

		if (this->empty())
			std::cout << "stack is empty" << std::endl;
		else
		{
			for (int iteration_count = 0; iteration_count < element_count; ++iteration_count)
			{
				type = typeid (data_type).name();
				if (setup)
				{
					for (int i = element_count - 1; i > -1; --i)
					{
						if (valueLength(_stack_[i]) > columns)
							columns = valueLength(_stack_[i]);
					}

					columns += 2;
					setup = false;
				}
				if (flag)
				{
					std::cout << '+';
					for (size_t j = 0; j < columns + 4; ++j)
						std::cout << '-';
					std::cout << '+' << std::endl;
					flag = false;
				}

				// если тип данных в стеке не символ или булево значение
				if (type[0] != 'b' && type[0] != 'c' && type[0] != 'a' && type[0] != 'h')
				{
					char* valueChanged = nullptr;
					unsigned int length = 0;

					value = std::to_string(_stack_[index]);
					// если тип данных вещественное число
					if (type[0] == 'f' || type[0] == 'd' || type[0] == 'e')
					{
						for (size_t i = value.length() - 1; value[i] != '.'; --i)
						{
							if (value[i] == '0')
								++length;
							else
								break;
						}
						valueChanged = new char[value.length() - length + 1];
						strncpy(valueChanged, value.c_str(), value.length() - length);
						valueChanged[value.length() - length] = '\0';
						counter = (columns - strlen(valueChanged)) / 2;

						std::cout << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							std::cout << '-';
						std::cout << '+' << ' ' << '|' << std::endl;

						std::cout << '|' << ' ' << '|' << ' ';
						for (size_t k = 1; k < counter; ++k)
							std::cout << ' ';
						std::cout << valueChanged;

						if (strlen(valueChanged) % 2 != 0 && columns % 2 == 0)
							std::cout << ' ';
						if (strlen(valueChanged) % 2 == 0 && columns % 2 != 0)
							std::cout << ' ';

						for (size_t k = 1; k < counter; ++k)
							std::cout << ' ';
						std::cout << ' ' << '|' << ' ' << '|' << std::endl;

						std::cout << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							std::cout << '-';
						std::cout << '+' << ' ' << '|' << std::endl;
					}
					// целочисленный тип данных
					else
					{
						counter = (columns - value.length()) / 2;

						std::cout << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							std::cout << '-';
						std::cout << '+' << ' ' << '|' << std::endl;

						std::cout << '|' << ' ' << '|' << ' ';
						for (size_t k = 1; k < counter; ++k)
							std::cout << ' ';
						std::cout << value;

						if (value.length() % 2 != 0 && columns % 2 == 0)
							std::cout << ' ';
						if (value.length() % 2 == 0 && columns % 2 != 0)
							std::cout << ' ';

						for (size_t k = 1; k < counter; ++k)
							std::cout << ' ';
						std::cout << ' ' << '|' << ' ' << '|' << std::endl;

						std::cout << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							std::cout << '-';
						std::cout << '+' << ' ' << '|' << std::endl;
					}
				}
				// если тип данных в стеке символ или булево значение
				else
				{
					std::cout << '|' << ' ' << '+';
					for (size_t i = 0; i < columns; ++i)
						std::cout << '-';
					std::cout << '+' << ' ' << '|' << std::endl;

					std::cout << '|' << ' ' << '|' << ' ';
					std::cout << _stack_[index];
					std::cout << ' ' << '|' << ' ' << '|';
					std::cout << std::endl;

					std::cout << '|' << ' ' << '+';
					for (size_t i = 0; i < columns; ++i)
						std::cout << '-';
					std::cout << '+' << ' ' << '|' << std::endl;
				}
				--index;
			}
			std::cout << '+';
			for (size_t j = 0; j < columns + 4; ++j)
				std::cout << '-';
			std::cout << '+' << std::endl;
		}

		system("pause");
	}

	// ############################ //
	// **************************** //
	// *** перегрузка операторов ** //
	// **************************** //
	// ############################ //

	// перегрузка оператора =
	stack& operator=(const stack& object)
	{
		if (_stack_ != nullptr) delete[] _stack_;

		size = object.size;
		element_count = object.element_count;
		_stack_ = new data_type[size];

		if (!object.empty())
		{
			for (unsigned int i = 0; i < object.element_count; ++i)
				_stack_[i] = object._stack_[i];
		}

		return *this;
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
			bool flag = true;
			bool setup = true;

			unsigned int columns = 0;
			unsigned int counter = 0;
			unsigned int index = 0;

			const char* type = nullptr;

			std::string value = "";

			index = element_count - 1;

			if (this->empty())
			{
				file << "stack is empty" << '\n';
				return false;
			}
			else
			{
				for (int iteration_count = 0; iteration_count < element_count; ++iteration_count)
				{
					type = typeid (data_type).name();

					if (setup)
					{
						for (int i = element_count - 1; i > -1; --i)
						{
							if(valueLength(_stack_[i]) > columns)
								columns = valueLength(_stack_[i]);
						}

						columns += 2;
						setup = false;
					}
					if (flag)
					{
						file << '+';
						for (size_t j = 0; j < columns + 4; ++j)
							file << '-';
						file << '+' << '\n';
						flag = false;
					}

					// если тип данных в стеке не символ или булево значение
					if (type[0] != 'b' && type[0] != 'c' && type[0] != 'a' && type[0] != 'h')
					{
						char* valueChanged = nullptr;
						unsigned int length = 0;

						value = std::to_string(_stack_[index]);
						// если тип данных вещественное число
						if (type[0] == 'f' || type[0] == 'd' || type[0] == 'e')
						{
							for (size_t i = value.length() - 1; value[i] != '.'; --i)
							{
								if (value[i] == '0')
									++length;
								else
									break;
							}
							valueChanged = new char[value.length() - length + 1];
							strncpy(valueChanged, value.c_str(), value.length() - length);
							valueChanged[value.length() - length] = '\0';
							counter = (columns - strlen(valueChanged)) / 2;

							file << '|' << ' ' << '+';
							for (size_t i = 0; i < columns; ++i)
								file << '-';
							file << '+' << ' ' << '|' << '\n';

							file << '|' << ' ' << '|' << ' ';
							for (size_t k = 1; k < counter; ++k)
								file << ' ';
							file << valueChanged;

							if (strlen(valueChanged) % 2 != 0 && columns % 2 == 0)
								file << ' ';
							if (strlen(valueChanged) % 2 == 0 && columns % 2 != 0)
								file << ' ';

							for (size_t k = 1; k < counter; ++k)
								file << ' ';
							file << ' ' << '|' << ' ' << '|' << '\n';

							file << '|' << ' ' << '+';
							for (size_t i = 0; i < columns; ++i)
								file << '-';
							file << '+' << ' ' << '|' << '\n';
						}
						// целочисленный тип данных
						else
						{
							counter = (columns - value.length()) / 2;

							file << '|' << ' ' << '+';
							for (size_t i = 0; i < columns; ++i)
								file << '-';
							file << '+' << ' ' << '|' << '\n';

							file << '|' << ' ' << '|' << ' ';
							for (size_t k = 1; k < counter; ++k)
								file << ' ';
							file << value;

							if (value.length() % 2 != 0 && columns % 2 == 0)
								file << ' ';
							if (value.length() % 2 == 0 && columns % 2 != 0)
								file << ' ';

							for (size_t k = 1; k < counter; ++k)
								file << ' ';
							file << ' ' << '|' << ' ' << '|' << '\n';

							file << '|' << ' ' << '+';
							for (size_t i = 0; i < columns; ++i)
								file << '-';
							file << '+' << ' ' << '|' << '\n';
						}
					}
					// если тип данных в стеке символ или булево значение
					else
					{
						file << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							file << '-';
						file << '+' << ' ' << '|' << '\n';

						file << '|' << ' ' << '|' << ' ';
						file << _stack_[index];
						file << ' ' << '|' << ' ' << '|';
						file << '\n';

						file << '|' << ' ' << '+';
						for (size_t i = 0; i < columns; ++i)
							file << '-';
						file << '+' << ' ' << '|' << '\n';
					}
					--index;
				}
				file << '+';
				for (size_t j = 0; j < columns + 4; ++j)
					file << '-';
				file << '+' << '\n';
			}

			file.close();
			return true;
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

	// ############################ //
	// **************************** //
	// ********* аксессоры ******** //
	// **************************** //
	// ############################ //
	
	// количество элементов в стеке
	int getElementCount() { return element_count; }
	// размер стека(выделенная память)
	int getSize() { return size; }
};