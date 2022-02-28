#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
	this->name = name;
	this->containsWarpSpace = containsWarpSpace;
}
string ShapeTwoD::getName()
{
	return name;
}
bool ShapeTwoD::getType()
{
	return containsWarpSpace;
}
string ShapeTwoD::toString()
{
	if(containsWarpSpace == true)
		return ("Name: " + name + "\nSpecial Type: WS\n");
	else
		return ("Name: " + name + "\nSpecial Type: NS\n");
}
void ShapeTwoD::setName(string name)
{
	this->name = name;
}
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}