#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>

static int counter = 0;

static double _store_revenue = 0.0; // выручка магазина
static int _clients_amount = 0; // количество клиентов

const int amount = 6;
const size_t length = 255;

struct _cash_register
{
	const char products[amount][length] =
	{
	  "игрушечная ёлка",
	  "игрушечный дед мороз",
	  "набор новогодних конфет",
	  "санки",
	  "лыжи",
	  "новогодние игрушки на ёлку"
	};

	const double price[amount] =
	{
	  23.99, 48.5,12.99,
	  47, 35.99, 19.99
	};

	int _products_amount = 0;

	double sum = 0.0;
};

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
	Задание 1. Пользователь вводит с клавиатуры две границы
	диапазона и число. Если число не попадает в диапазон,
	программа просит пользователя повторно ввести число,
	и так до тех пор, пока он не введет число правильно.
	*/
	int _starting_range = 0;
	int _end_range = 0;
	int number = 0;

Start:
	std::cout << "введите начальный диапазон: ";
	std::cin >> _starting_range;
	std::cout << "введите конечный диапазон: ";
	std::cin >> _end_range;
	if (_end_range < _starting_range) goto Start;
InputNumber:
	std::cout << "введите число: ";
	std::cin >> number;
	if (number < _starting_range || number > _end_range) goto InputNumber;

	/*
	Задание 2. Написать имитацию кассового аппарата для
	магазина, торгующего новогодними товарами. Кассир
	должен выбрать товар из списка, ввести его количество,
	затем выбрать следующий товар. По завершению ввода
	вывести на экран всю сумму покупки. Предусмотреть
	наличие скидки. В списке товаров должно быть не меньше
	4-х товаров, должна отображаться их цена. Предусмотреть
	неправильно вводимые данные.
	■ Реализовать возможность обслуживания нескольких
	клиентов подряд;
	■ Хранение общей выручки магазина;
	■ Ограничить количество товара в магазине.
	*/
	int choise = 0;

	_cash_register client;

client:
	system("cls");

	std::cout << "\tменю\n";
	std::cout << "1. обслужить клиетна\n";
	std::cout << "0. завершить работу\n";

	std::cout << "выберите операцию: ";
	std::cin >> choise;

	if (choise == 1)
	{
		++_clients_amount;

		client.sum = 0.0;
		client._products_amount = 0;

		do
		{
			system("cls");
			std::cout << "\tменю\n";
			std::cout << "1. приобрести товар\n";
			std::cout << "2. посчитать итоговую стоимость\n";
			std::cout << "3. завершить покупки\n";

			std::cout << "выберите операцию: ";
			std::cin >> choise;

			switch (choise)
			{
			case 1:
				std::cout << "\n\tсписок товаров\n";
				for (size_t i = 0; i < amount; ++i)
				{
					std::cout << i + 1 << ". " << client.products[i] << " - " << client.price[i] << '$' << std::endl;
				}
			retry:
				std::cout << "выберите товар: ";
				std::cin >> choise;

				std::cout << "введите количество товара который вы преобретаете: ";
				std::cin >> client._products_amount;

				if (choise > 0 && choise < 7)
				{
					client.sum += client.price[choise - 1] * client._products_amount;
				}
				else
				{
					std::cout << "введите прввильный номер товара\n";
					goto retry;
				}
				break;
			case 2:
				std::cout << "сумма к оплате: " << client.sum << '$' << std::endl;
				system("pause");
				break;
			case 3:
				_store_revenue += client.sum;
				goto client;
				break;
			default:
				std::cout << "введите правильный номер операции: " << std::endl;
				system("pause");
				break;
			}
		} while (choise);
	}
	else
	{
		std::cout << "общая выручка магазина за сегодня: " << _store_revenue << '$' << std::endl;
		std::cout << "количество обслуженных клиентов: " << _clients_amount << std::endl;
	}
}
/*
const size_t size = 6;

	int choise = 0;

	std::string _product_name[size]{ "Tree: 29.95$", "sled: 5.43$", "skiing: 7.68$", "lollipop: 12.6$", "toy Santa Claus: 43$", "set of christmas toys: 35$" };
	double _product_price[size]{ 29.95, 5.43, 7.68, 12.6, 43, 35 };

	double proceeds = 0.0; //выручка
	double price = 0.0;
	int amount = 0;
	double sum = 0.0;
	double discount = 0.0;

	do
	{
		counter = 0;

		Purchase:
		std::cout << "1. select a product from the list" << std::endl;
		std::cout << "0. complete shopping" << std::endl;
		std::cout << "select operation: ";
		std::cin >> choise;
		if (choise == 1)
		{
			ProductName:
			std::cout << "\tProduct List\n";
			for (size_t i = 0; i < size; ++i)
				_create_menu(_product_name[i]);
			std::cout << "select a product: ";
			std::cin >> choise;
			if (choise < 1 || choise > 6)
			{
				std::cout << "enter the correct number";
				goto ProductName;
			}
			else if (choise > 1 && choise < 7)
			{
				price = _product_price[choise - 1];
				std::cout << "enter product quantity: ";
				std::cin >> amount;
				sum += price * amount;
			}
		}

		std::cout << "amount to pay: " << sum << std::endl;

		std::cout << "1. continue shopping" << std::endl;
		std::cout << "0. exit" << std::endl;
		std::cout << "select operations: ";
		std::cin >> choise;
	} while (choise);

	return 0;
*/