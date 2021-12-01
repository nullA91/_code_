#pragma once

#include "constants.h"
#include "functions.h"
#include "libraries.h"

struct geometric_figure
{
	double width = 0.0;
	double length = 0.0;

	void moving();
	void resizing();
	void output(int& X, int& Y);
};

struct point
{
	double X = 0;
	double Y = 0;

	double distance(const point& point);
};

struct simple_fraction
{
	int numerator = 0;
	int denominator = 0;
	int whole_part = 0;

	bool sign = true;

	simple_fraction addition(const simple_fraction& fraction);
	simple_fraction subtraction(const simple_fraction& fraction);
	simple_fraction multiplication();
	simple_fraction division();
	void fraction_reduction();
	void fraction_conversion();

	void output();
};