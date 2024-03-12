#include "Canvas.h"
#include <iostream>
#include <cstdarg>
using namespace std;

Canvas::Canvas(int lines, int columns)
{
	if (lines > 1000 || columns > 1000)
		cout << "Se depaseste marimea acceptata" << endl;
	else
	{
		this->height = lines;
		this->length = columns;
		this->clear();
	}
}

void Canvas::set_pixel(int x, int y, char value)
{
	array[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		int x = va_arg(args, int);     
		int y = va_arg(args, int);     
		int val = va_arg(args, int);   

		if (x >= 0 && x <height && y >= 0 && y <length) {
			set_pixel(x, y, val);
		}
	}

	va_end(args);
}

void Canvas::clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			array[i][j] = ' ';
}

void Canvas::print() const
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
}
