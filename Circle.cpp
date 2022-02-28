#include "Circle.h"

Circle::Circle(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Circle::setData2(int x, int y, int radius) //set centre point and radius
{
    this->midx = x;
    this->midy = y;
    this->radius = radius;
}
double Circle::computeArea()
{
	area = pie * radius * radius;
	return area;
}
double Circle::getArea()
{
	return area;
}
bool Circle::isPointInShape(int x, int y)
{
	int xdist = midx-x; //distance of x from centre
    int ydist = midy-y; //distance of y from centre
    if (((xdist * xdist) + (ydist * ydist)) < (radius * radius)) //a^2 + b^2 = c^2. if c^2 < r^2
    {
		if((x != midx) && (y != midy))
			return true;
	}
	return false;
}
bool Circle::isPointOnShape(int x, int y)
{
	int xdist = midx-x; //distance of x from centre
    int ydist = midy-y; //distance of y from centre
	if (((xdist * xdist) + (ydist * ydist)) == (radius * radius)) //a^2 + b^2 = c^2. if c^2 == r^2
    {
		return true;
	}
	return false;
}
string Circle::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string(area) + " units square\n";
    output += "Centre Point: [" + to_string(midx) + ", " + to_string(midy) + "]\n";
	output += "Radius: " + to_string(radius) + " units\n\n";
	output += "Points on perimeter:";
	for (int i = (midx - radius); i <= (midx + radius);i++)
    {
		for (int j = (midy - radius); j <= (midy + radius); j++)
        {
			if (isPointOnShape(i, j) == true)
            {
				output += " (" + to_string(i) + ", " + to_string(j) + "),";
            }
		}
	}
    output.pop_back();
	output += "\n\nPoints within shape: ";
    if(radius == 1)
    {
		output += "no points within shape ";
    }
    else
    {
        for (int i = (midx - radius); i <= (midx + radius);i++)
        {
            for (int j = (midy - radius); j <= (midy + radius); j++)
            {
                if(isPointInShape(i, j) == true)
                {
                    output += " (" + to_string(i) + ", " + to_string(j) + "),";
                }
            }
        }
    }
    output.pop_back();
	output += "\n";
	
	return output;
}
