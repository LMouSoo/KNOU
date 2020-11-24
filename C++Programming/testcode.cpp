#include <iostream>
#include "polygon.h"
using namespace std;

int main ()
{
    int inputnumberofvertices;
    double x, y;
    cout << "꼭짓점의 갯수를 정수로 입력하세요" <<endl;
    cin >> inputnumberofvertices;                                          //사용자로부터 다각형의 정보를 입력받음
    if (inputnumberofvertices<3){
        cout << "다각형은 세 개 이상의 꼭짓점 좌표로 정의됩니다." << endl;
        return 0;
    }
    C2D *inputvertexcoordinates = new C2D[inputnumberofvertices];
    for(int i = 0; i < inputnumberofvertices; i++){
        cout << i+1 << "번째 꼭짓점의 x좌표 y좌표를 입력하세요." << endl;
        cin >> x >> y;
        inputvertexcoordinates[i] = {x, y};
        //각각의 꼭짓점의 위치가 동일한지 아닌지 판정이 필요할 수 있으나 보류
    }

    cout << "==========poly1 생성==========" << endl;
    polygon poly1(inputnumberofvertices, inputvertexcoordinates);
    cout << "poly1의 넓이는 " << poly1.area_of_polygon() << endl;
    poly1.print_polygon_info();
    cout << "이 다각형의 꼭짓점의 좌표가 저장된 메모리 위치는" <<endl;
    poly1.vertex_coordinates_memory_address();

    cout << "==========poly1을 복사해 poly2 생성==========" << endl;
    polygon poly2(poly1);
    cout << "이 다각형의 넓이는 " << poly2.area_of_polygon() << endl;
    poly2.print_polygon_info();
    cout << "이 다각형의 꼭짓점의 좌표가 저장된 메모리 위치는" <<endl;
    poly2.vertex_coordinates_memory_address();

    cout << "==========poly1을 이동해 poly3 생성==========" << endl;
    polygon poly3(move(poly1));                                     //move()를 이용해 이동 생성자를 호출
    cout << "이 다각형의 넓이는 " << poly3.area_of_polygon() << endl;
    poly3.print_polygon_info();
    cout << "이 다각형의 꼭짓점의 좌표가 저장된 메모리 위치는" <<endl;
    poly3.vertex_coordinates_memory_address();

    cout << "==========이동된 poly1의 정보는 없어짐==========" << endl;
    poly1.print_polygon_info();
    cout << "메모리 위치도 비워짐" << endl;
    poly1.vertex_coordinates_memory_address();
}