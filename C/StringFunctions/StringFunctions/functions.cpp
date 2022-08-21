#include "functions.h"
// функция определения длинны строки
int _length_string(char* _transmitted_string)
{
	int _characters_number = 0; // целочисленная переменная для подсчета количества символов в строке

	while (*_transmitted_string) // цикл пока строка не дойдет до нулевого(\0) символа
	{
		++_characters_number; // если символ строки не равен \0, количество символов возрастает на 1
		_transmitted_string++; // перемещение указателя к следующему символу строки
	};

	return _characters_number; // возвращает количество символов в строке
}
// функция определения длинны константной строки
int _length_string(const char* _transmitted_string)
{
	int _characters_number = 0; // целочисленная переменная для подсчета количества символов в строке

	while (*_transmitted_string) // цикл пока строка не дойдет до нулевого(\0) символа
	{
		++_characters_number; // если символ строки не равен \0, количество символов возрастает на 1
		_transmitted_string++; // перемещение указателя к следующему символу строки
	};

	return _characters_number; // возвращает количество символов в строке
}
// функция проверки совпадения строк
bool _string_matching(char* _current_string, char* _transmitted_string)
{
	bool _returned_value = 1; // Булевская переменная, для проверки строк на совпадение

	for (int i = 0, j = 0; i < _length_string(_current_string); ++i, ++j) // цикл для сравнения каждого символа в двух строках
		if (_current_string[i] != _transmitted_string[j]) // условие если символ одной из строк не равен символу другой строки тогда
			_returned_value = 0; // присвоить переменной для проверки строк значение ноль

	return _returned_value; // возвращает переменную для проверки строк
}
// функция для переворота(инверсии) строки
char* _reverse_string(char* _transmitted_string)
{
	unsigned int size = _length_string(_transmitted_string); // целочисленная переменная равная значению символов в строке
	char symbol; // символьная переменная, помогает в пузырьковой сортировке

	for (int i = 0, j = size - 1; i < size / 2; ++i, --j) // цикл пузырьковой сортировки, будет выполняться (размер строки / 2) раз
	{
		symbol = _transmitted_string[i]; // присваивание символов начальных позиций в символьную переменную
		_transmitted_string[i] = _transmitted_string[j]; // присваивание символов конечных позиций в начальные позиции
		_transmitted_string[j] = symbol; // присваивание символов начальных позиций в конецные позиции
	}

	return _transmitted_string; // возвращает инверсированную строку
}
// функция проверки баланса парных скобок
bool _balance_brackets(char* _transmitted_string)
{
	bool _returned_value = 0; // баланс скобок, если 0 - баланс скобок нарушен, если 1 - баланс скобок выдержан, если -1 скобок нет

	int _counter_parenthes_open = 0; // количество вхождений круглых открывающихся скобок
	int _counter_parenthes_close = 0; // количество вхождений круглых закрывающихся скобок
	int _counter_square_brackets_open = 0; // количество вхождений квадратных открывающихся скобок
	int _counter_square_brackets_close = 0; // количество вхождений квадратных закрывающихся скобок
	int _counter_curly_brackets_open = 0; // количество вхождений фигурных открывающихся скобок
	int _counter_curly_brackets_close = 0; // количество вхождений фигурных закрывающихся скобок

	int index = 0; // индекс символа в строке

	bool exit = false; // Булевская переменная, если на момент проверки условия количество закрытых скобок превышает количество открытых скобок 
	
	while (_transmitted_string[index] != '\0' && !exit) // пока не конец строки
	{
		if (_transmitted_string[index] == '(') // если символ строки открывающаяся круглая скобка
			++_counter_parenthes_open; // колличество открытых круглых скобок увеличить на один
		else if (_transmitted_string[index] == ')') // если символ строки закрывающаяся круглая скобка
		{
			++_counter_parenthes_close; // колличество закрывающих круглых скобок увеличить на один
			if (_counter_parenthes_close > _counter_parenthes_open) // если количество закрытых круглых скобок больше количества открытых круглых скобок
				exit = true; // присвоить переменной для выходя значение true, выполнение цикла прекратиться, баланс скобок нарушен
		}

		else if (_transmitted_string[index] == '[') // если символ строки открывающаяся квадратная скобка
			++_counter_square_brackets_open; // колличество открытых квадратных скобок увеличить на один
		else if (_transmitted_string[index] == ']') // если символ строки закрывающаяся квадратная скобка
		{
			++_counter_square_brackets_close; // колличество закрывающих квадратных скобок увеличить на один
			if (_counter_square_brackets_close > _counter_square_brackets_open) // если количество закрытых квадратных скобок больше количества открытых квадратных скобок
				exit = true; // присвоить переменной для выходя значение true, выполнение цикла прекратиться, баланс скобок нарушен
		}

		else if (_transmitted_string[index] == '{') // если символ строки открывающаяся фигурная скобка
			++_counter_curly_brackets_open; // колличество открытых фигурных скобок увеличить на один
		else if (_transmitted_string[index] == '}') // если символ строки закрывающаяся фигурная скобка
		{
			++_counter_curly_brackets_close; // колличество закрывающих фигурных скобок увеличить на один
			if (_counter_curly_brackets_close > _counter_curly_brackets_open) // если количество закрытых фигурных скобок больше количества открытых фигурных скобок
				exit = true; // присвоить переменной для выходя значение true, выполнение цикла прекратиться, баланс скобок нарушен
		}
		
		index++; // увелечение индекса позиции в строке на один
	}

	// выполняем проверку баланса скобок
	if (_counter_parenthes_open == 0 && _counter_parenthes_close == 0 && _counter_square_brackets_open == 0 && _counter_square_brackets_close == 0 && _counter_curly_brackets_open == 0 && _counter_curly_brackets_close == 0)
		_returned_value = -1; // во входной строке нет скобок
	else
		if (_counter_parenthes_open == _counter_parenthes_close && _counter_square_brackets_open == _counter_square_brackets_close && _counter_curly_brackets_open == _counter_curly_brackets_close)
			_returned_value = 1; // баланс скобок не нарушен

	return _returned_value; // возврат значения; баланс скобок, если 0 - баланс скобок нарушен, если 1 - баланс скобок выдержан, если -1 скобок нет
}
//  функция поиска первого вхождения подстроки в строку
int _occurence_substring(char* _current_string, char* _transmitted_string)
{
	int position = 0; // целочисленная переменная, позиция первого вхождения подстроки
	
	for (int i = 0, j = 0; i < _length_string(_current_string); ++i) // цикл проходит по всем символам текущей строки
	{
		if (_current_string[i] == _transmitted_string[j]) // условие для сравнивает символ текущей строки с символом передаваемой строки
		{
			++j; // переменная j увеличивается на единицу
			if (j == _length_string(_transmitted_string)) // условие если j будет равно длине передаваемой строки тогда:
			{
				position = i - j + 2; // переменной position присвоить i(индекс символа в текущей строке(символ текущей строки равный последнему символу передаваемой строки)) - j(индекс символа в передаваемой строке(длина передаваемой строки)) + 2
				break; // завершить цикл for
			}
		}
		else // иначе:
		{
			j = 0; // перемонной j присвоить 0
		}
	}

	return position; // возвращение номера позиции первого вхождения подстроки
}
// функция вставки строки во вторую строку с указанной позиции
char* _insert_n_string(char* _current_string, char* _transmitted_string, int position)
{
	char* _temp_string = new char[_length_string(_current_string) + _length_string(_transmitted_string) + 1]; // массив char для создания временной строки

	if (position > 0 && position < _length_string(_current_string) - 1) // условие если размер текущей строки может вместить в себя количество символов передоваемой строки и номер введенной позиции не превышает длину строки и не является отрицательным
	{
		for (int i = 0; i < position - 1; ++i) // цикл копирует начальные символы текущей строки до введенной позиции
			_temp_string[i] = _current_string[i];
		for (int i = position - 1, j = 0; j < _length_string(_transmitted_string); ++j, ++i) // цикл начиная с места под номеров введенной текущей позиции копирует все символы передаваемой строки
			_temp_string[i] = _transmitted_string[j];
		for (int i = position - 1, j = (_length_string(_current_string) + _length_string(_transmitted_string)) - position; i < _length_string(_current_string); ++i, ++j) // цикл начиная с места следующего за введенным номером позиции копирует символы текущей строки
			_temp_string[j] = _current_string[i];
		
		_temp_string[_length_string(_current_string) + _length_string(_transmitted_string)] = '\0'; // присваивание заверщающего символа строки, строке получившейся от слияния двух строк
		
		return _temp_string; // возвращение строки состоящей из двух строк
	}
	else
		return _current_string; // возвращение исходной строки в первоночальном виде
}

// функция извлечения k символов входной строки, начиная с позиции N
char* _сut_string(char* _transmitted_string, int length, int position)
{
	char* _temp_string = new char[length + 1]; // массив char для создания временной строки

	if (position > 0 && length + position - 1 <= _length_string(_transmitted_string)) // условие если позиция не отрицательяна, не равна 0 и количество извленкаемых символов с указанной позиции не превышает длину строки
	{
		for (int i = position - 1, j = 0; j < length; ++j, ++i) // цикл копирования символов передаваемой строки с введенной позиции, введенное количество раз
			_temp_string[j] = _transmitted_string[i]; // присвоение символов строки временной строке

		_temp_string[length] = '\0';  // присваивание завершающего символа в конец временной строки

		return _temp_string; // возврат временной строки
	}
	else
		return _transmitted_string; // возвращение исходной строки в первоночальном виде
}

/*
int _occurence_substring(char* _current_string, char* _transmitted_string)
{
	int position = 0; // целочисленная переменная, позиция первого вхождения подстроки
	int _current_string_size = _length_string(_current_string); // целочисленная переменная, длина текущей строки
	char* _temp_string = new char[_length_string(_transmitted_string) + 2]; // символьный массив для создания временной строки

	int _current_string_position = 0; // целочмсленная переменная, номер позиции текущей строки
	int _transmitted_string_position = 0; // целочисленная переменная, номер позиции подстроки
	int i = 0; // целочисленная переменная, номер позиции символа в текущей строке совпапдающий с первым символом подстроки
	int j = 1; // целочисленная переменная, номер позиции символа временной строки следующий за начальным и.т.д

	for (; _current_string_position < _current_string_size; ++_current_string_position) // цикл проходит по каждому символу в текущей строке
	{
		if (_current_string[_current_string_position] == _transmitted_string[_transmitted_string_position]) // условие если символ текущей строки равен первому символу подстроки
		{
			position = _current_string_position + 1; // позиции первого вхождения подстроки присваивается значение позиции символа в текущей строке равное первому символу в подстроке
			_temp_string[_transmitted_string_position] = _transmitted_string[_transmitted_string_position]; // присваивание символа подстроки, символу временной строки
			i = _current_string_position + 1; // увеличение на один номера позиции символа в текущей строке совпапдающего с первым символом подстроки
			_transmitted_string_position++; // увеличение на один номера позиции подстроки
			while (_current_string[i] == _transmitted_string[_transmitted_string_position]) // цикл пока символ текущей строки равен символу подстроки
			{
				_temp_string[j] = _transmitted_string[_transmitted_string_position]; // присваивание символа подстроки, символу временной строки
				i++; // увеличение на один номера позиции символа в текущей строке
				j++; // увелечение на один номера позиции символа в временной строке
				_transmitted_string_position++; // увеличение на один номера позиции подстроки
			}
			_temp_string[_length_string(_transmitted_string)] = '\0'; // присваивание завершающего символа в конец временной строки
		}
		if (_string_matching(_temp_string, _transmitted_string)) // условие в котором функция проверяет совпадает ли полученная временная строка с подстрокой
			break; // если условие соблюдено завершается цикл for
		else // если полученная временная строка и подстрока не совпадают тогда
		{
			position = 0; // номеру позиции первого вхождения подстроки присвоить ноль
			_transmitted_string_position = 0; // номеру позиции первого символа подстроки присвоить ноль
			i = 0; // номеру позиции символа в текущей строке совпапдающего с первым символом подстроки присвоить ноль
			j = 1; // номеру позиции символа временной строки следующего за начальным и.т.д присвоить один
			continue; // продолжить выполнение цикла for
		}
	}

	delete[] _temp_string;

	return position; // возвращение номера позиции первого вхождения подстроки
}
*/