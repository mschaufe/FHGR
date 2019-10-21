#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_


class Rectangle
{
public:
	Rectangle(int h, int w);
	int get_height();
	int get_width();
	void set_height(int value);
	void set_width(int value);
	int get_area();
	int get_circumference();

private:
	int height;
	int width;
};



#endif	// _RECTANGLE_H_
