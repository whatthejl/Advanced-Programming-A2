#include "Square.h"

Square::Square(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Square::setData(int *x, int *y)
{
    bool check = false;
    int i = 1;
    while (check == false) //sets minx and maxx
    {
        if (x[0] == x[i])
            i++;
        else if (x[0] > x[i])
        {
            this->minx = x[i];
            this->maxx = x[0];
            check = true;
        }
        else if (x[i] > x[0])
        {
            this->minx = x[0];
            this->maxx = x[i];
            check = true;
        }
    }
    i = 1;
    check = false;
    while (check == false) //sets miny and maxy
    {
        if (y[0] == y[i])
            i++;
        else if (y[0] > y[i])
        {
            this->miny = y[i];
            this->maxy = y[0];
            check = true;
        }
        else if (y[i] > y[0])
        {
            this->miny = y[0];
            this->maxy = y[i];
            check = true;
        }
    }
    this->xdist = maxx - minx; //sets length
    this->ydist = maxy - miny; //sets breadth
    for (int i = 0; i < 4; i++)
    {
    	this->x[i] = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
    	this->y[i] = y[i];
    }
    //this->x = x;
    //this->y = y;
}
double Square::computeArea()
{
    area = xdist * ydist;
	return area;
}
double Square::getArea()
{
	return area;
}
bool Square::isPointInShape(int x, int y)
{
    if (minx < x && x < maxx) //check if parameters are in the boundaries of shape
    {
		if (miny < y && y < maxy)
			return true;
	}
	return false;
}
bool Square::isPointOnShape(int x, int y)
{
	if (x == minx || x == maxx) //check if parameters are withing the boundaries of shape
    {
        if (miny < y && y < maxy)
            return true;
    }
    else if (y == miny || y == maxy)
    {
        if (minx < x && x < maxx)
            return true;
    }
    return false;
}
string Square::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string((int)area) + " units square\n";
    output += "Vertices:\n";
    for (int i = 0; i < 4; i++)
    {
        output += "Point [" + to_string(i) + "]: (" + to_string(x[i]) + ", " + to_string(y[i]) + ")\n";
    }
    /*
	output += "Point [0]: (" + to_string(minx) + ", " + to_string(miny) + ")\n";
    output += "Point [1]: (" + to_string(minx) + ", " + to_string(maxy) + ")\n";
    output += "Point [2]: (" + to_string(maxx) + ", " + to_string(maxy) + ")\n";
    output += "Point [3]: (" + to_string(maxx) + ", " + to_string(miny) + ")\n\n"; 
    */
	output += "Points on perimeter:";
	for (int i = minx; i <= maxx;i++)
    {
		for (int j = miny; j <= maxy; j++)
        {
			if (isPointOnShape(i, j) == true)
            {
				output += " (" + to_string(i) + ", " + to_string(j) + "),";
            }
		}
	}
    output.pop_back();
	output += "\n\nPoints within shape:";
    if(area == 1)
    {
		output += "no points within shape ";
    }
    else
    {
        for (int i = minx; i <= maxx;i++)
        {
            for (int j = miny; j <= maxy; j++)
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
