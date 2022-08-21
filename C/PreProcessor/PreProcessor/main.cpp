#define NINTEGER
#define LENGTH 10

#include "Functions.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise = 0;
	int index = 0;
	int value = 0;
	char symbol = '\0';
	_data_type array[LENGTH];

	do {
		printf("%s", "\tменю\n");
		printf("%s", "1. заполнение массива.\n");
		printf("%s", "2. поиск минимального элемента массива.\n");
		printf("%s", "3. поиск максимального элемента массива.\n");
		printf("%s", "4. сортировка массива.\n");
		printf("%s", "5. изменение значения массива.\n");
		printf("%s", "6. вывод массива на консоль.\n");
		printf("%s", "выберите пункт меню: ");
		scanf_s("%d", &choise);
		switch (choise) {
		case 1:
			_fill_array(array, LENGTH);
			break;
		case 2:
			printf("%s%d%c", "минимальное значение в массиве: ", _finding_minimum_item(array, LENGTH), '\n');
			break;
		case 3:
			printf("%s%d%c", "максимальное значение в массиве: ", _finding_maximum_item(array, LENGTH), '\n');
			break;
		case 4:
			_sorting_array(array, LENGTH);
			break;
		case 5:
			printf("%s", "введите порядковый номер значения в массиве: ");
			scanf_s("%d", &index);
			printf("%s", "введите новое значение: ");
			scanf_s("%d", &value);
			_change_value_array(array, LENGTH, index, value);
			break;
		case 6:
			_output_array(array, 10);
			break;
		default:
			printf("%s", "в меню нет пункта под выбраным номером, введите другой номер.\n");
			break;
		}
		printf("%s", "повторить операцию(y/n)? ");
		scanf_s("%c", &symbol);
		scanf_s("%c", &symbol);
	} while (symbol != 'n' && symbol != 'N');

	return 0;
}