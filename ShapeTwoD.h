#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;
	public:
		ShapeTwoD(string, bool);
		string getName();
		bool getType();
		virtual string toString();
		virtual double computeArea(){return 1.0;};
		virtual double getArea(){return 1.0;};
		virtual void setData(int[], int[]){};
		virtual void setData2(int, int, int){};
		virtual bool isPointInShape(int, int){return false;};
		virtual bool isPointOnShape(int, int){return false;};
		void setName(string);
		void setContainsWarpSpace(bool);	
};
#endif
