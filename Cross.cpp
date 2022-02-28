#include "Cross.h"

Cross::Cross(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Cross::setData(int *x, int *y)
{
    vector<int> tempminx;
    vector<int> tempmaxx;
    vector<int> tempminy;
    vector<int> tempmaxy;
    for (int i = 0; i < 12; i++)
    {
    	this->x[i] = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
    	this->y[i] = y[i];
    }
    //this->x = x;
    //this->y = y;
    minx = x[0];
    maxx = x[0];
    miny = y[0];
    maxy = y[0];
    for(int i = 0; i < 12; i++) //find x coord of left and right points
    {
        if(x[i] < minx)
            minx = x[i];
        else if(x[i] > maxx)
            maxx = x[i];
    }
    for(int i = 0; i < 12; i++) //find y coord of top and bottom points
    {
        if(y[i] < miny)
            miny = y[i];
        else if(y[i] > maxy)
            maxy = y[i];
    }
    for (int i = 0; i < 12; i++)
    {
        if (x[i] == minx)
            tempminx.push_back(y[i]);
        else if (x[i] == maxx)
            tempmaxx.push_back(y[i]);
        if (y[i] == miny)
            tempminy.push_back(x[i]);
        else if (y[i] == maxy)
            tempmaxy.push_back(x[i]);
    } //tempmin x and y, tempmax x and y should have 2 int in each vector (coordinates)
    if (tempminx[0] < tempminx[1]) //tempmin and tempmax will be stored in other variables
    {
        leftboty = tempminx[0];
        lefttopy = tempminx[1];
    }
    else 
    {
        leftboty = tempminx[1];
        lefttopy = tempminx[0];
    }
    if (tempmaxx[0] < tempmaxx[1])
    {
        rightboty = tempmaxx[0];
        righttopy = tempmaxx[1];
    }
    else 
    {
        rightboty = tempmaxx[1];
        righttopy = tempmaxx[0];
    }
    if (tempminy[0] < tempminy[1])
    {
        botleftx = tempminy[0];
        botrightx = tempminy[1];
    }
    else 
    {
        botleftx = tempminy[1];
        botrightx = tempminy[0];
    }
    if (tempmaxy[0] < tempmaxy[1])
    {
        topleftx = tempmaxy[0];
        toprightx = tempmaxy[1];
    }
    else 
    {
        topleftx = tempmaxy[1];
        toprightx = tempmaxy[0];
    }
    tempminx.clear();
    tempmaxx.clear();
    tempminy.clear();
    tempmaxy.clear();
    //sets the virtual lines that breaks the cross into 5 rectangles (closer to the corner)
    if (lefttopy > righttopy)
        topboty = lefttopy;
    else
        topboty = righttopy;
    if (leftboty < rightboty)
        bottopy = leftboty;
    else
        bottopy = rightboty;
    if (topleftx < botleftx)
        leftrightx = topleftx;
    else
        leftrightx = botleftx;
    if (toprightx > botrightx)
        rightleftx = toprightx;
    else
        rightleftx = botrightx;
}
double Cross::computeArea()
{
    toparea = (maxy - topboty) * (toprightx - topleftx);
    botarea = (bottopy - miny) * (botrightx - botleftx);
    leftarea = (leftrightx - minx) * (lefttopy - leftboty);
    rightarea = (maxx - rightleftx) * (righttopy - rightboty);
    midarea = (rightleftx - leftrightx) * (topboty - bottopy);
    area = toparea + leftarea + rightarea + botarea + midarea;
	return area;
}
double Cross::getArea()
{
	return area;
}
//checks if parameters are within boundaries of the 5 rectangles, except the middle which is inclusive of boundaries
bool Cross::isPointInShape(int x, int y) 
{
    if (minx < x && x <= leftrightx)
    {
		if (leftboty < y && y < lefttopy)
			return true;
	}
    else if (topboty <= y && y < maxy)
    {
		if (topleftx < x && x < toprightx)
			return true;
	}
    else if (rightleftx <= x && x < maxx)
    {
		if (rightboty < y && y < righttopy)
			return true;
	}
    else if (miny < y && y <= bottopy)
    {
		if (botleftx < x && x < botrightx)
			return true;
	}
    else if (bottopy <= y && y <= topboty)
    {
		if (leftrightx <= x && x <= rightleftx)
			return true;
	}
	return false;
}
//checks if the parameters are on the 12 lines on the corners of the cross
bool Cross::isPointOnShape(int x, int y) 
{
	if (x == minx)
    {
        if (leftboty < y && y < lefttopy)
            return true;
    }
    if (x == maxx)
    {
        if (rightboty < y && y < righttopy)
            return true;
    }
    if (x == topleftx)
    {
        if (lefttopy < y && y < maxy)
            return true;
    }
    if (x == toprightx)
    {
        if (righttopy < y && y < maxy)
            return true;
    }
    if (x == botleftx)
    {
        if (miny < y && y < leftboty)
            return true;
    }
    if (x == botrightx)
    {
        if (miny < y && y < rightboty)
            return true;
    }
    if (y == maxy)
    {
        if (topleftx < x && x < toprightx)
            return true;
    }
    if (y == miny)
    {
        if (botleftx < x && x < botrightx)
            return true;
    }
    if (y == lefttopy)
    {
        if (minx < x && x < topleftx)
            return true;
    }
    if (y == leftboty)
    {
        if (minx < x && x < botleftx)
            return true;
    }
    if (y == righttopy)
    {
        if (toprightx < x && x < maxx)
            return true;
    }
    if (y == rightboty)
    {
        if (botrightx < x && x < maxx)
            return true;
    }
    return false;
}
string Cross::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string((int)area) + " units square\n";
    output += "Vertices:\n";
    /*for (int i = 0; i < 12; i++)
    {
        output += "Point [" + to_string(i) + "]: (" + to_string(x[i]) + ", " + to_string(y[i]) + ")\n";
    }*/
    output += "Point [0]: (" + to_string(botleftx) + ", " + to_string(miny) + ")\n";
    output += "Point [1]: (" + to_string(botrightx) + ", " + to_string(miny) + ")\n";
    output += "Point [2]: (" + to_string(botrightx) + ", " + to_string(rightboty) + ")\n";
    output += "Point [3]: (" + to_string(maxx) + ", " + to_string(rightboty) + ")\n";
    output += "Point [4]: (" + to_string(maxx) + ", " + to_string(righttopy) + ")\n";
    output += "Point [5]: (" + to_string(toprightx) + ", " + to_string(righttopy) + ")\n";
    output += "Point [6]: (" + to_string(toprightx) + ", " + to_string(maxy) + ")\n";
    output += "Point [7]: (" + to_string(topleftx) + ", " + to_string(maxy) + ")\n";
    output += "Point [8]: (" + to_string(topleftx) + ", " + to_string(lefttopy) + ")\n";
    output += "Point [9]: (" + to_string(minx) + ", " + to_string(lefttopy) + ")\n";
    output += "Point [10]: (" + to_string(minx) + ", " + to_string(leftboty) + ")\n";
    output += "Point [11]: (" + to_string(botleftx) + ", " + to_string(leftboty) + ")\n";
	output += "Points on perimeter:";
	for (int i = minx; i <= maxx; i++)
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
