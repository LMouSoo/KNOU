#include <iostream>		// std::cout, std::cin 사용
#include <cstring>		// memcpy 사용
#include "polygon.h"
using namespace std;	//std::cout, std::cin에서 std 생략

polygon::polygon(const int numberofvertices, const C2D *vertexcoordinates = nullptr)							//생성자, 좌표정보가 없는 빈 polygon 선언이 필요한 경우가 있어 기본값 nullptr 지정
: number_of_vertices{numberofvertices}
{
	vertex_coordinates = new C2D[numberofvertices];
	if (vertexcoordinates) memcpy(vertex_coordinates, vertexcoordinates, sizeof(C2D) * numberofvertices);		//빈 polygon 선언이 아닌경우(vertexcoordinates이 nullptr이면 False, 정보가 존재하면 True)에 좌표정보를 복사
	cout << "생성자호출" << endl;																				 //실제 구현에는 필요하지 않으나, 학습 목적으로 눈으로 확인하기 위한 출력
}
polygon::polygon(const polygon& polygonobject)																	//복사 생성자
: number_of_vertices{polygonobject.number_of_vertices}
{
	vertex_coordinates = new C2D[number_of_vertices];
	memcpy(vertex_coordinates, polygonobject.vertex_coordinates, sizeof(C2D) * number_of_vertices);
	cout << "복사생성자호출" << endl;																	  		 //실제 구현에는 필요하지 않으나, 학습 목적으로 눈으로 확인하기 위한 출력
}
polygon::polygon(polygon&& polygonobject)																		//이동 생성자
: number_of_vertices{polygonobject.number_of_vertices}, vertex_coordinates{polygonobject.vertex_coordinates}
{
	polygonobject.vertex_coordinates = nullptr;
	polygonobject.number_of_vertices = 0;
	cout << "이동생성자호출" << endl;																			 //실제 구현에는 필요하지 않으나, 학습 목적으로 눈으로 확인하기 위한 출력
}
polygon::~polygon()																								//소멸자
{
	delete[] vertex_coordinates;
	cout << "소멸자호출" << endl;																		 		 //실제 구현에는 필요하지 않으나, 학습 목적으로 눈으로 확인하기 위한 출력
}
double polygon::area_of_polygon() const																			//다각형의 넓이 반환
{
	double area = 0;
	for(int i = 0; i < number_of_vertices; i++){																//신발끈공식 이용
		area += (vertex_coordinates[i].x*vertex_coordinates[i+1].y)-(vertex_coordinates[i].y*vertex_coordinates[i+1].x);
	}
	area += (vertex_coordinates[number_of_vertices-1].x*vertex_coordinates[0].y)-(vertex_coordinates[number_of_vertices-1].y*vertex_coordinates[0].x);
	if (area < 0) area =-area;
	area = area/2;
	return area;
}
void polygon::print_polygon_info() const																		//다각형의 정보 출력
{
	if (vertex_coordinates == nullptr){																			//다각형 좌표 저장 포인터가 비어있는경우(nullptr)
		cout << "출력할 정보가 없습니다." << endl;
		return;
	}
	cout << "이 다각형의 꼭짓점의 갯수는 " << number_of_vertices << endl;
	cout << "이 다각형의 꼭짓점의 좌표는" << endl;
	for (int i = 0; i < number_of_vertices; i++){
		cout << "x : " << vertex_coordinates[i].x << ", y: " << vertex_coordinates[i].y << endl;
	}
}
void polygon::vertex_coordinates_memory_address() const															//다각형 좌표 저장 포인터 출력
{																												//이동 생성자로 생성된 포인터가 이전 포인터와 동일함을 확인하기 위한 학습목적
	if(vertex_coordinates == nullptr){																			//다각형 좌표 저장 포인터가 비어있는경우(nullptr)
		cout << "nullptr" << endl;
		return;
	}
	cout << vertex_coordinates << endl;
}
polygon polygon::move_polygon(const double x, const double y)													//수업 내용처럼 다각형의 위치를 옮긴 rvalue를 만들어 이동 생성자를 호출하려 했으나
{																												//사용한 컴파일러인 g++이 이동생성자를 지원하는 c++11부터 이미 수업 내용처럼 함수 내부에 객체를 만들어 return하는 경우 반드시 복사 생략을 하도록 되어있어서 이동 생성자가 호출되지 않음
	polygon tmp(number_of_vertices);																			//따라서 main함수에서 사용되지 못함
	for(int i = 0; i < number_of_vertices; i++){
		tmp.vertex_coordinates[i] = {vertex_coordinates[i].x+x,vertex_coordinates[i].y+y};
		cout << tmp.vertex_coordinates[i].x << "," << tmp.vertex_coordinates[i].y << endl;
	}
	return tmp;
}

