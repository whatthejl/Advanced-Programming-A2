#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h"

using namespace std;

class Square : public ShapeTwoD
{
	private:
		int minx;
		int maxx;
		int miny;
		int maxy;
		int xdist;
		int ydist;
		int x[4];
		int y[4];
		double area;
	public:
		Square(string, bool);
		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif
