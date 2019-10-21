#include "rectangle.h"



Rectangle::Rectangle(int h, int w)
{
	height = h;
	width = w;
}



int Rectangle::get_height()
{
	return height;
}



int Rectangle::get_width()
{
	return width;
}



void Rectangle::set_height(int value)
{
	height = value;
}



void Rectangle::set_width(int value)
{
	width = value;
}



int Rectangle::get_area()
{
	return height * width;
}



int Rectangle::get_circumference()
{
	return 2 * height + 2 * width;
}
