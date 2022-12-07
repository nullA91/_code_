#pragma once
// тип данных значения
template <typename data_type>
unsigned int valueDataType(data_type value)
{
	bool exit = false;

	unsigned int return_value = 0;

	const unsigned int size_integer = 11;
	const unsigned int size_float = 3;
	const unsigned int size_char_bool = 4;

	const char* type = typeid(value).name();

	const char type_integer[size_integer] = { 'w', 'D', 's', 't', 'i', 'j', 'l', 'm', 'x', 'y' };
	const char type_float[size_float] = { 'f', 'd', 'e' };
	const char type_char_bool[size_char_bool] = { 'b', 'c', 'a', 'h' };

	for (unsigned int i = 0; i < size_integer; ++i)
	{
		if (!exit)
		{
			if (i < size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : (type[0] == type_float[i]) ? 2 : (type[0] == type_char_bool[i]) ? 3 : 0;
				if (return_value) exit = true;
			}
			else if (i == size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : (type[0] == type_char_bool[i]) ? 3 : 0;
				if (return_value) exit = true;
			}
			else if (i > size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : 0;
				if (return_value) exit = true;
			}
		}
		else break;
	}

	return return_value;
}
// длинна(количество цифр[символов]) значения
template <typename data_type>
unsigned int valueLength(data_type value)
{
	unsigned int length = 0;
	unsigned int size = 0;

	unsigned int type = 0;

	char* valueChanged = nullptr;

	std::string _value_ = "";

	type = valueDataType(value);
	_value_ = std::to_string(value);

	// целочисленный тип данных
	if (type == 1)
		length = _value_.length();
	// если тип данных вещественное число
	else if (type == 2)
	{
		for (size_t i = _value_.length() - 1; _value_[i] != '.'; --i)
		{
			if (_value_[i] == '0')
				++size;
			else
				break;
		}
		valueChanged = new char[_value_.length() - size + 1];
		strncpy(valueChanged, _value_.c_str(), _value_.length() - size);
		valueChanged[_value_.length() - size] = '\0';
		length = strlen(valueChanged);
	}
	// тип данных символ или булево значение
	else if (type == 3)
		length = 1;
	// пользовательский тип дынных
	else
		length = 0;

	return length;
}