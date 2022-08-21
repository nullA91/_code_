#include "functions.h"
// ������� ����������� ������ ������
int _length_string(char* _transmitted_string)
{
	int _characters_number = 0; // ������������� ���������� ��� �������� ���������� �������� � ������

	while (*_transmitted_string) // ���� ���� ������ �� ������ �� ��������(\0) �������
	{
		++_characters_number; // ���� ������ ������ �� ����� \0, ���������� �������� ���������� �� 1
		_transmitted_string++; // ����������� ��������� � ���������� ������� ������
	};

	return _characters_number; // ���������� ���������� �������� � ������
}
// ������� ����������� ������ ����������� ������
int _length_string(const char* _transmitted_string)
{
	int _characters_number = 0; // ������������� ���������� ��� �������� ���������� �������� � ������

	while (*_transmitted_string) // ���� ���� ������ �� ������ �� ��������(\0) �������
	{
		++_characters_number; // ���� ������ ������ �� ����� \0, ���������� �������� ���������� �� 1
		_transmitted_string++; // ����������� ��������� � ���������� ������� ������
	};

	return _characters_number; // ���������� ���������� �������� � ������
}
// ������� �������� ���������� �����
bool _string_matching(char* _current_string, char* _transmitted_string)
{
	bool _returned_value = 1; // ��������� ����������, ��� �������� ����� �� ����������

	for (int i = 0, j = 0; i < _length_string(_current_string); ++i, ++j) // ���� ��� ��������� ������� ������� � ���� �������
		if (_current_string[i] != _transmitted_string[j]) // ������� ���� ������ ����� �� ����� �� ����� ������� ������ ������ �����
			_returned_value = 0; // ��������� ���������� ��� �������� ����� �������� ����

	return _returned_value; // ���������� ���������� ��� �������� �����
}
// ������� ��� ����������(��������) ������
char* _reverse_string(char* _transmitted_string)
{
	unsigned int size = _length_string(_transmitted_string); // ������������� ���������� ������ �������� �������� � ������
	char symbol; // ���������� ����������, �������� � ����������� ����������

	for (int i = 0, j = size - 1; i < size / 2; ++i, --j) // ���� ����������� ����������, ����� ����������� (������ ������ / 2) ���
	{
		symbol = _transmitted_string[i]; // ������������ �������� ��������� ������� � ���������� ����������
		_transmitted_string[i] = _transmitted_string[j]; // ������������ �������� �������� ������� � ��������� �������
		_transmitted_string[j] = symbol; // ������������ �������� ��������� ������� � �������� �������
	}

	return _transmitted_string; // ���������� ��������������� ������
}
// ������� �������� ������� ������ ������
bool _balance_brackets(char* _transmitted_string)
{
	bool _returned_value = 0; // ������ ������, ���� 0 - ������ ������ �������, ���� 1 - ������ ������ ��������, ���� -1 ������ ���

	int _counter_parenthes_open = 0; // ���������� ��������� ������� ������������� ������
	int _counter_parenthes_close = 0; // ���������� ��������� ������� ������������� ������
	int _counter_square_brackets_open = 0; // ���������� ��������� ���������� ������������� ������
	int _counter_square_brackets_close = 0; // ���������� ��������� ���������� ������������� ������
	int _counter_curly_brackets_open = 0; // ���������� ��������� �������� ������������� ������
	int _counter_curly_brackets_close = 0; // ���������� ��������� �������� ������������� ������

	int index = 0; // ������ ������� � ������

	bool exit = false; // ��������� ����������, ���� �� ������ �������� ������� ���������� �������� ������ ��������� ���������� �������� ������ 
	
	while (_transmitted_string[index] != '\0' && !exit) // ���� �� ����� ������
	{
		if (_transmitted_string[index] == '(') // ���� ������ ������ ������������� ������� ������
			++_counter_parenthes_open; // ����������� �������� ������� ������ ��������� �� ����
		else if (_transmitted_string[index] == ')') // ���� ������ ������ ������������� ������� ������
		{
			++_counter_parenthes_close; // ����������� ����������� ������� ������ ��������� �� ����
			if (_counter_parenthes_close > _counter_parenthes_open) // ���� ���������� �������� ������� ������ ������ ���������� �������� ������� ������
				exit = true; // ��������� ���������� ��� ������ �������� true, ���������� ����� ������������, ������ ������ �������
		}

		else if (_transmitted_string[index] == '[') // ���� ������ ������ ������������� ���������� ������
			++_counter_square_brackets_open; // ����������� �������� ���������� ������ ��������� �� ����
		else if (_transmitted_string[index] == ']') // ���� ������ ������ ������������� ���������� ������
		{
			++_counter_square_brackets_close; // ����������� ����������� ���������� ������ ��������� �� ����
			if (_counter_square_brackets_close > _counter_square_brackets_open) // ���� ���������� �������� ���������� ������ ������ ���������� �������� ���������� ������
				exit = true; // ��������� ���������� ��� ������ �������� true, ���������� ����� ������������, ������ ������ �������
		}

		else if (_transmitted_string[index] == '{') // ���� ������ ������ ������������� �������� ������
			++_counter_curly_brackets_open; // ����������� �������� �������� ������ ��������� �� ����
		else if (_transmitted_string[index] == '}') // ���� ������ ������ ������������� �������� ������
		{
			++_counter_curly_brackets_close; // ����������� ����������� �������� ������ ��������� �� ����
			if (_counter_curly_brackets_close > _counter_curly_brackets_open) // ���� ���������� �������� �������� ������ ������ ���������� �������� �������� ������
				exit = true; // ��������� ���������� ��� ������ �������� true, ���������� ����� ������������, ������ ������ �������
		}
		
		index++; // ���������� ������� ������� � ������ �� ����
	}

	// ��������� �������� ������� ������
	if (_counter_parenthes_open == 0 && _counter_parenthes_close == 0 && _counter_square_brackets_open == 0 && _counter_square_brackets_close == 0 && _counter_curly_brackets_open == 0 && _counter_curly_brackets_close == 0)
		_returned_value = -1; // �� ������� ������ ��� ������
	else
		if (_counter_parenthes_open == _counter_parenthes_close && _counter_square_brackets_open == _counter_square_brackets_close && _counter_curly_brackets_open == _counter_curly_brackets_close)
			_returned_value = 1; // ������ ������ �� �������

	return _returned_value; // ������� ��������; ������ ������, ���� 0 - ������ ������ �������, ���� 1 - ������ ������ ��������, ���� -1 ������ ���
}
//  ������� ������ ������� ��������� ��������� � ������
int _occurence_substring(char* _current_string, char* _transmitted_string)
{
	int position = 0; // ������������� ����������, ������� ������� ��������� ���������
	
	for (int i = 0, j = 0; i < _length_string(_current_string); ++i) // ���� �������� �� ���� �������� ������� ������
	{
		if (_current_string[i] == _transmitted_string[j]) // ������� ��� ���������� ������ ������� ������ � �������� ������������ ������
		{
			++j; // ���������� j ������������� �� �������
			if (j == _length_string(_transmitted_string)) // ������� ���� j ����� ����� ����� ������������ ������ �����:
			{
				position = i - j + 2; // ���������� position ��������� i(������ ������� � ������� ������(������ ������� ������ ������ ���������� ������� ������������ ������)) - j(������ ������� � ������������ ������(����� ������������ ������)) + 2
				break; // ��������� ���� for
			}
		}
		else // �����:
		{
			j = 0; // ���������� j ��������� 0
		}
	}

	return position; // ����������� ������ ������� ������� ��������� ���������
}
// ������� ������� ������ �� ������ ������ � ��������� �������
char* _insert_n_string(char* _current_string, char* _transmitted_string, int position)
{
	char* _temp_string = new char[_length_string(_current_string) + _length_string(_transmitted_string) + 1]; // ������ char ��� �������� ��������� ������

	if (position > 0 && position < _length_string(_current_string) - 1) // ������� ���� ������ ������� ������ ����� �������� � ���� ���������� �������� ������������ ������ � ����� ��������� ������� �� ��������� ����� ������ � �� �������� �������������
	{
		for (int i = 0; i < position - 1; ++i) // ���� �������� ��������� ������� ������� ������ �� ��������� �������
			_temp_string[i] = _current_string[i];
		for (int i = position - 1, j = 0; j < _length_string(_transmitted_string); ++j, ++i) // ���� ������� � ����� ��� ������� ��������� ������� ������� �������� ��� ������� ������������ ������
			_temp_string[i] = _transmitted_string[j];
		for (int i = position - 1, j = (_length_string(_current_string) + _length_string(_transmitted_string)) - position; i < _length_string(_current_string); ++i, ++j) // ���� ������� � ����� ���������� �� ��������� ������� ������� �������� ������� ������� ������
			_temp_string[j] = _current_string[i];
		
		_temp_string[_length_string(_current_string) + _length_string(_transmitted_string)] = '\0'; // ������������ ������������ ������� ������, ������ ������������ �� ������� ���� �����
		
		return _temp_string; // ����������� ������ ��������� �� ���� �����
	}
	else
		return _current_string; // ����������� �������� ������ � �������������� ����
}

// ������� ���������� k �������� ������� ������, ������� � ������� N
char* _�ut_string(char* _transmitted_string, int length, int position)
{
	char* _temp_string = new char[length + 1]; // ������ char ��� �������� ��������� ������

	if (position > 0 && length + position - 1 <= _length_string(_transmitted_string)) // ������� ���� ������� �� �������������, �� ����� 0 � ���������� ������������ �������� � ��������� ������� �� ��������� ����� ������
	{
		for (int i = position - 1, j = 0; j < length; ++j, ++i) // ���� ����������� �������� ������������ ������ � ��������� �������, ��������� ���������� ���
			_temp_string[j] = _transmitted_string[i]; // ���������� �������� ������ ��������� ������

		_temp_string[length] = '\0';  // ������������ ������������ ������� � ����� ��������� ������

		return _temp_string; // ������� ��������� ������
	}
	else
		return _transmitted_string; // ����������� �������� ������ � �������������� ����
}

/*
int _occurence_substring(char* _current_string, char* _transmitted_string)
{
	int position = 0; // ������������� ����������, ������� ������� ��������� ���������
	int _current_string_size = _length_string(_current_string); // ������������� ����������, ����� ������� ������
	char* _temp_string = new char[_length_string(_transmitted_string) + 2]; // ���������� ������ ��� �������� ��������� ������

	int _current_string_position = 0; // ������������� ����������, ����� ������� ������� ������
	int _transmitted_string_position = 0; // ������������� ����������, ����� ������� ���������
	int i = 0; // ������������� ����������, ����� ������� ������� � ������� ������ ������������ � ������ �������� ���������
	int j = 1; // ������������� ����������, ����� ������� ������� ��������� ������ ��������� �� ��������� �.�.�

	for (; _current_string_position < _current_string_size; ++_current_string_position) // ���� �������� �� ������� ������� � ������� ������
	{
		if (_current_string[_current_string_position] == _transmitted_string[_transmitted_string_position]) // ������� ���� ������ ������� ������ ����� ������� ������� ���������
		{
			position = _current_string_position + 1; // ������� ������� ��������� ��������� ������������� �������� ������� ������� � ������� ������ ������ ������� ������� � ���������
			_temp_string[_transmitted_string_position] = _transmitted_string[_transmitted_string_position]; // ������������ ������� ���������, ������� ��������� ������
			i = _current_string_position + 1; // ���������� �� ���� ������ ������� ������� � ������� ������ ������������� � ������ �������� ���������
			_transmitted_string_position++; // ���������� �� ���� ������ ������� ���������
			while (_current_string[i] == _transmitted_string[_transmitted_string_position]) // ���� ���� ������ ������� ������ ����� ������� ���������
			{
				_temp_string[j] = _transmitted_string[_transmitted_string_position]; // ������������ ������� ���������, ������� ��������� ������
				i++; // ���������� �� ���� ������ ������� ������� � ������� ������
				j++; // ���������� �� ���� ������ ������� ������� � ��������� ������
				_transmitted_string_position++; // ���������� �� ���� ������ ������� ���������
			}
			_temp_string[_length_string(_transmitted_string)] = '\0'; // ������������ ������������ ������� � ����� ��������� ������
		}
		if (_string_matching(_temp_string, _transmitted_string)) // ������� � ������� ������� ��������� ��������� �� ���������� ��������� ������ � ����������
			break; // ���� ������� ��������� ����������� ���� for
		else // ���� ���������� ��������� ������ � ��������� �� ��������� �����
		{
			position = 0; // ������ ������� ������� ��������� ��������� ��������� ����
			_transmitted_string_position = 0; // ������ ������� ������� ������� ��������� ��������� ����
			i = 0; // ������ ������� ������� � ������� ������ ������������� � ������ �������� ��������� ��������� ����
			j = 1; // ������ ������� ������� ��������� ������ ���������� �� ��������� �.�.� ��������� ����
			continue; // ���������� ���������� ����� for
		}
	}

	delete[] _temp_string;

	return position; // ����������� ������ ������� ������� ��������� ���������
}
*/