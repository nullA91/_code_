#include "..\Headers\Point.h"

// ����
bool Point::input()
{
	const unsigned int length = 10;

	char value[10];

	X:
	std::cout << "enter a coordinate along the axis x: ";
	std::cin >> value;
	x = atoi(value);
	if (!x) goto X;
	z.setRez(x);

	Y:
	std::cout << "enter a coordinate along the axis y: ";
	std::cin >> value;
	y = atoi(value);
	if (!y) goto Y;
	z.setImz(y);

	return true;
}
// �����
bool Point::output()
{
	std::cout << z << std::endl;
	return true;
}
// ������ ������ � ����
void Point::write_data_file(std::ofstream& file, const std::string& path)
{
	file.open(path, std::ios::app);

	if (file.is_open())
		file << z;
	else
		std::cout << "Error opening file";
}
