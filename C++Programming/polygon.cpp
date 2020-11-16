#include <iostream>
#include "polygon.h"
using namespace std;

polygon::polygon()
{
	this->numberofvertices = 0;
	cout << "생성자테스트" << endl;
}
polygon::~polygon()
{
	cout << "소멸자테스트" << endl;
}


//struct C2D {
//	double x, y; // x축 좌표와 y축 좌표
//};