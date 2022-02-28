#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD
{
	private:
		int x[12];
		int y[12];
		int minx;
		int maxx;
		int miny;
		int maxy;
		int botleftx;
		int botrightx;
		int leftboty;
		int lefttopy;
		int topleftx;
		int toprightx;
		int righttopy;
		int rightboty;
		int topboty;
		int bottopy;
		int leftrightx;
		int rightleftx;
		int toparea;
		int leftarea;
		int rightarea;
		int botarea;
		int midarea;
		int area;
	public:
		Cross(string, bool);
		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif
