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
		printf("%s", "\t����\n");
		printf("%s", "1. ���������� �������.\n");
		printf("%s", "2. ����� ������������ �������� �������.\n");
		printf("%s", "3. ����� ������������� �������� �������.\n");
		printf("%s", "4. ���������� �������.\n");
		printf("%s", "5. ��������� �������� �������.\n");
		printf("%s", "6. ����� ������� �� �������.\n");
		printf("%s", "�������� ����� ����: ");
		scanf_s("%d", &choise);
		switch (choise) {
		case 1:
			_fill_array(array, LENGTH);
			break;
		case 2:
			printf("%s%d%c", "����������� �������� � �������: ", _finding_minimum_item(array, LENGTH), '\n');
			break;
		case 3:
			printf("%s%d%c", "������������ �������� � �������: ", _finding_maximum_item(array, LENGTH), '\n');
			break;
		case 4:
			_sorting_array(array, LENGTH);
			break;
		case 5:
			printf("%s", "������� ���������� ����� �������� � �������: ");
			scanf_s("%d", &index);
			printf("%s", "������� ����� ��������: ");
			scanf_s("%d", &value);
			_change_value_array(array, LENGTH, index, value);
			break;
		case 6:
			_output_array(array, 10);
			break;
		default:
			printf("%s", "� ���� ��� ������ ��� �������� �������, ������� ������ �����.\n");
			break;
		}
		printf("%s", "��������� ��������(y/n)? ");
		scanf_s("%c", &symbol);
		scanf_s("%c", &symbol);
	} while (symbol != 'n' && symbol != 'N');

	return 0;
}