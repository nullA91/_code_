/*
С помощью директивы #define написать следующие макросы :
Нахождение меньшего из двух чисел;
Нахождение большего из двух чисел;
Возведение числа в квадрат;
Возведение числа в степень;
Проверка числа на четность;
Проверка числа на нечетность;
*/
#include <math.h>
#include <stdio.h>

#define min(_number_one, _number_two) ((_number_one < _number_two) ? _number_one : _number_two)
#define max(_number_one, _number_two) ((_number_one > _number_two) ? _number_one : _number_two)
#define squaring(number) number * number
#define exponentiation(number, power) (pow(number, power))
#define EvenNumber(number) number % 2 == 0
#define OddNumber(number) number % 2 != 0

int main() {
	short choise = 0;
	int _number_one = 0, _number_two = 0;

	do {
		printf("%s", "\n\tmenu\n");
		printf("%s", "1. finding the smaller of the two numbers.\n");
		printf("%s", "2. finding the larger of the two numbers.\n");
		printf("%s", "3. construction of the square.\n");
		printf("%s", "4. construction of the power.\n");
		printf("%s", "5. check the number for parity.\n");
		printf("%s", "6. check the number for odd.\n");
		printf("%s", "select menu item: ");
		scanf_s("%d", &choise);
		switch (choise) {
		case 1:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_two);
			printf("%s%d%c", "the smaller of the two numbers: ", min(_number_one, _number_two), '\n');
			break;
		case 2:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_two);
			printf("%s%d%c", "the greater of the two numbers: ", max(_number_one, _number_two), '\n');
			break;
		case 3:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			printf("%s%d%c", "square root of a number: ", squaring(_number_one), '\n');
			break;
		case 4:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			printf("%s", "enter a number degree: ");
			scanf_s("%d", &_number_two);
			_number_one = exponentiation(_number_one, _number_two);
			printf("%s%d%s%d%s%d%c", "the number ", _number_one, " in degree ", _number_two, " is equal to ", _number_one, '\n');
			break;
		case 5:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			if (EvenNumber(_number_one))
				printf("%s", "the number is even\n");
			else
				printf("%s", "the number is odd.\n");
			break;
		case 6:
			printf("%s", "enter a number: ");
			scanf_s("%d", &_number_one);
			if (OddNumber(_number_one))
				printf("%s", "the number is odd\n");
			else
				printf("%s", "the number is even.\n");
			break;
		default:
			printf("%s", "no menu item selected, select another menu item.\n");
			break;
		}
		printf("%s", "retry the operation(1. yes/0. no)?: ");
		scanf_s("%d", &choise);
	} while (choise);

	return 0;
}