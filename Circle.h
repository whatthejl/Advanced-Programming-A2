#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"

using namespace std;

class Circle : public ShapeTwoD
{
	private:
		int midx;
		int midy;
		int radius;
		const double pie = 3.141592;
		double area;
	public:
		Circle(string, bool);
		void setData2(int, int, int) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif
