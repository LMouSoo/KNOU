#include <iostream>
#include <cstring>
#include "polygon.h"
using namespace std;

polygon::polygon(const int numberofvertices, const C2D *vertexcoordinates = nullptr)
: number_of_vertices{numberofvertices}
{
	vertex_coordinates = new C2D[numberofvertices];
	if (vertexcoordinates) memcpy(vertex_coordinates, vertexcoordinates, sizeof(C2D) * numberofvertices);
	cout << "생성자호출" << endl;
}
polygon::polygon(const polygon& polygonobject)
: number_of_vertices{polygonobject.number_of_vertices}
{
	vertex_coordinates = new C2D[number_of_vertices];
	memcpy(vertex_coordinates, polygonobject.vertex_coordinates, sizeof(C2D) * number_of_vertices);
	cout << "복사생성자호출" << endl;
}
polygon::polygon(polygon&& polygonobject)
: number_of_vertices{polygonobject.number_of_vertices}, vertex_coordinates{polygonobject.vertex_coordinates}
{
	polygonobject.vertex_coordinates = nullptr;
	polygonobject.number_of_vertices = 0;
	cout << "이동생성자호출" << endl;
}
polygon::~polygon()
{
	delete[] vertex_coordinates;
	cout << "소멸자호출" << endl;
}
double polygon::area_of_polygon() const
{
	double area = 0;
	for(int i = 0; i < number_of_vertices; i++){
		area += (vertex_coordinates[i].x*vertex_coordinates[i+1].y)-(vertex_coordinates[i].y*vertex_coordinates[i+1].x);
	}
	area += (vertex_coordinates[number_of_vertices-1].x*vertex_coordinates[0].y)-(vertex_coordinates[number_of_vertices-1].y*vertex_coordinates[0].x);
	if (area < 0) area =-area;
	area = area/2;
	return area;
}
void polygon::print_polygon_info() const
{
	if (vertex_coordinates == nullptr){
		cout << "출력할 정보가 없습니다." << endl;
		return;
	}
	cout << "이 다각형의 꼭짓점의 갯수는 " << number_of_vertices<< "개 입니다." << endl;
	cout << "이 다각형의 꼭짓점의 좌표는" << endl;
	for (int i = 0; i < number_of_vertices; i++){
		cout << "x : " << vertex_coordinates[i].x << ", y: " << vertex_coordinates[i].y << endl;
	}
	cout << "입니다." << endl;
}
polygon polygon::move_polygon(const double x, const double y)
{
	polygon tmp(number_of_vertices);
	for(int i = 0; i < number_of_vertices; i++){
		tmp.vertex_coordinates[i] = {vertex_coordinates[i].x+x,vertex_coordinates[i].y+y};
		cout << tmp.vertex_coordinates[i].x << "," << tmp.vertex_coordinates[i].y << endl;
	}
	return tmp;
}

