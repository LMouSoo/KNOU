#include <iostream>
#include <cstring>
#include "polygon.h"
using namespace std;

polygon::polygon(const int numberofvertices, const C2D *vertexcoordinates)
: numberofvertices{numberofvertices}
{
	this->vertexcoordinates = new C2D[numberofvertices];
	memcpy(this->vertexcoordinates, vertexcoordinates, sizeof(C2D) * numberofvertices);
	cout << "생성자테스트" << endl;
}
polygon::~polygon()
{
	cout << "소멸자테스트" << endl;
}
void polygon::printpolygoninfo() const
{
	cout << numberofvertices << endl;
	cout << vertexcoordinates[0].x << endl;
}

