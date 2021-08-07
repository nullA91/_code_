#include <ctime>
#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
		Задание 1. Написать игру «Угадай число». Программа
		загадывает число в диапазоне от 1 до 500. Пользователь
		пытается его угадать. После каждой попытки программа
		выдает подсказки, больше или меньше его число загадан-
		ного. В конце программа выдает статистику: за сколько
		попыток угадано число, сколько времени это заняло.
		Предусмотреть выход по 0, в случае, если пользователю
		надоело угадывать число.
	*/

	int hours = 0;
	int minutes = 0;

	int number = 0;
	int _random_number = 0;
	int counter = 0;
	int choise = 0;

	double seconds = 0.0;

	time_t start, end;

	srand(time(NULL));

	do
	{
		std::cout << "1. играть\n";
		std::cout << "0. выход\n";

		std::cout << "выберите операцию: ";
		std::cin >> choise;

		if (choise)
		{
			start = 0, end = 0;

			time(&start);

			_random_number = rand() % 500 + 1;

			counter = 0;

			while ((number != _random_number))
			{
				++counter;

				std::cout << "введите число: ";
				std::cin >> number;

				if (number < _random_number)
					std::cout << "введенное число меньше загаданного\n";
				else if (number > _random_number)
					std::cout << "введенное число больше загаданного\n";
			}
			time(&end);

			seconds = difftime(end, start);

			hours = seconds / 3600;
			minutes = (seconds - hours * 3600) / 60;
			seconds = seconds - minutes * 60;

			std::cout << "вы угадали" << std::endl;
			std::cout << "попыток: " << counter << std::endl;
			std::cout << "затараченное время: " << hours << ':' << minutes << ':' << seconds << std::endl;
		}
	} while (choise);

	/*
		 Задание 2. Написать программу-конвертер валют. Реа-
		 лизовать общение с пользователем через меню.
	*/
	double _russian_ruble = 0.0;
	double hryvnia = 0.0;
	int dollar = 0;
	int euro = 0;
	int quid = 0;

	double purchase = 0.0; // покупка(н.к)
	double sale = 0.0; // продажа(в.к)

	double sum = 0.0;

	do
	{
		std::cout << "\tменю\n";
		std::cout << "1. рубль\n";
		std::cout << "2. гривна\n";
		std::cout << "3. доллар\n";
		std::cout << "4. евро\n";
		std::cout << "5. фунт стерлингов\n";
		std::cout << "0. выход\n";

		std::cout << "выберите операцию: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			std::cout << "введите сумму: ";
			std::cin >> sum;

			std::cout << "\tменю\n";
			std::cout << "1. продажа рубля за гривну\n";
			std::cout << "2. продажа рубля за доллар\n";
			std::cout << "3. продажа рубля за евро\n";
			std::cout << "4. продажа рубля за фунт стерлингов\n";
			std::cout << "выберите операцию: ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				std::cout << "введите курс покупки рубля: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " гривны\n";
				break;
			case 2:
				std::cout << "введите курс покупки рубля: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " $\n";
				break;
			case 3:
				std::cout << "введите курс покупки рубля: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " евро\n";
				break;
			case 4:
				std::cout << "введите курс покупки рубля: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " £\n";
				break;
			default:
				std::cout << "выберите правильный номер операции" << std::endl;
				break;
			}
			break;
		case 2:
			std::cout << "введите сумму: ";
			std::cin >> sum;

			std::cout << "\tменю\n";
			std::cout << "1. продажа гривны за рубль\n";
			std::cout << "2. продажа гривны за доллар\n";
			std::cout << "3. продажа гривны за евро\n";
			std::cout << "4. продажа гривны за фунт стерлингов\n";
			std::cout << "выберите операцию: ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				std::cout << "введите курс покупки гривны: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " рубля\n";
				break;
			case 2:
				std::cout << "введите курс покупки гривны: ";
				std::cin >> sale;
				sum /= sale;
				std::cout << "к оплате: " << sum << " $\n";
				break;
			case 3:
				std::cout << "введите курс покупки гривны: ";
				std::cin >> sale;
				sum /= sale;
				std::cout << "к оплате: " << sum << " евро\n";
				break;
			case 4:
				std::cout << "введите курс покупки гривны: ";
				std::cin >> sale;
				sum /= sale;
				std::cout << "к оплате: " << sum << " £\n";
			default:
				std::cout << "выберите правильный номер операции" << std::endl;
				break;
			}
			break;
		case 3:
			std::cout << "введите сумму: ";
			std::cin >> sum;

			std::cout << "\tменю\n";
			std::cout << "1. продажа доллара за рубль\n";
			std::cout << "2. продажа доллара за гривну\n";
			std::cout << "3. продажа доллара за евро\n";
			std::cout << "4. продажа доллара за фунт стерлингов\n";
			std::cout << "выберите операцию: ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				std::cout << "введите курс покупки доллара: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " рубля\n";
				break;
			case 2:
				std::cout << "введите курс покупки доллара: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " гривны\n";
				break;
			case 3:
				std::cout << "введите курс покупки доллара: ";
				std::cin >> sale;
				sum *= sale;
				std::cout << "к оплате: " << sum << " евро\n";
				break;
			case 4:
				std::cout << "введите курс покупки доллара: ";
				std::cin >> sale;
				sum *= sale;
				std::cout << "к оплате: " << sum << " £\n";
				break;
			default:
				std::cout << "выберите правильный номер операции" << std::endl;
				break;
			}
			break;
		case 4:
			std::cout << "введите сумму: ";
			std::cin >> sum;

			std::cout << "\tменю\n";
			std::cout << "1. продажа евро за рубль\n";
			std::cout << "2. продажа евро за гривну\n";
			std::cout << "3. продажа евро за доллар\n";
			std::cout << "4. продажа евро за фунт стерлингов\n";
			std::cout << "выберите операцию: ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				std::cout << "введите курс покупки евро: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " рубля\n";
				break;
			case 2:
				std::cout << "введите курс покупки евро: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " гривны\n";
				break;
			case 3:
				std::cout << "введите курс покупки евро: ";
				std::cin >> purchase;
				sum *= purchase;
				std::cout << "к оплате: " << sum << " $\n";
				break;
			case 4:
				std::cout << "введите курс покупки евро: ";
				std::cin >> sale;
				sum *= sale;
				std::cout << "к оплате: " << sum << " £\n";
				break;
			default:
				std::cout << "выберите правильный номер операции" << std::endl;
				break;
			}
			break;
		default:
			std::cout << "выберите правильный номер операции" << std::endl;
			break;
		}

	} while (choise);

	return 0;
}