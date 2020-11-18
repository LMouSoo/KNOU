#include <iostream>
#include <cstring>
#include "polygon.h"
using namespace std;

polygon::polygon(const int numberofvertices, const C2D *vertexcoordinates = nullptr)
: numberofvertices{numberofvertices}
{
	this->vertexcoordinates = new C2D[numberofvertices];
	if (vertexcoordinates) memcpy(this->vertexcoordinates, vertexcoordinates, sizeof(C2D) * numberofvertices);
	cout << "생성자테스트" << endl;
}
polygon::polygon(const polygon& polygonobject)
: numberofvertices{polygonobject.numberofvertices}
{
	this->vertexcoordinates = new C2D[numberofvertices];
	memcpy(this->vertexcoordinates, polygonobject.vertexcoordinates, sizeof(C2D) * numberofvertices);
	cout << "복사생성자테스트" << endl;
}
polygon::polygon(polygon&& polygonobject)
: numberofvertices{polygonobject.numberofvertices}, vertexcoordinates{polygonobject.vertexcoordinates}
{
	polygonobject.vertexcoordinates = nullptr;
	polygonobject.numberofvertices = 0;
	cout << "이동생성자테스트" << endl;
}
polygon::~polygon()
{
	delete[] vertexcoordinates;
	cout << "소멸자테스트" << endl;
}
void polygon::printpolygoninfo() const
{
	cout << numberofvertices << endl;
	cout << vertexcoordinates[0].x << endl;
}
polygon polygon::movepolygon(double x, double y)
{
	polygon tmp(numberofvertices);
	for(int i = 0; i < numberofvertices; i++){
		tmp.vertexcoordinates[i] = {vertexcoordinates[i].x+x,vertexcoordinates[i].y+y};
		cout << tmp.vertexcoordinates[i].x << "," << tmp.vertexcoordinates[i].y << endl;
	}
	return tmp;
}

