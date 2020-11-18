#include <iostream>
#include "polygon.h"
using namespace std;

int main ()
{
    int inputnumberofvertices;
    double x, y;
    cout << "꼭짓점의 갯수를 정수로 입력하세요" <<endl;
    cin >> inputnumberofvertices;
    if (inputnumberofvertices<3){
        cout << "다각형은 세 개 이상의 꼭짓점 좌표로 정의됩니다." << endl;
        return 0;
    }
    C2D *inputvertexcoordinates = new C2D[inputnumberofvertices];
    for(int i = 0; i < inputnumberofvertices; i++){
        cout << i+1 << "번째 꼭짓점의 x좌표 y좌표를 입력하세요." << endl;
        cin >> x >> y;
        inputvertexcoordinates[i] = {x, y};
    }
    polygon poly1(inputnumberofvertices, inputvertexcoordinates);
    poly1.print_polygon_info();
    cout << poly1.area_of_polygon() << endl;
    polygon poly2(poly1);
    poly2.print_polygon_info();
    polygon poly3(move(poly2));
    poly3.print_polygon_info();
    poly2.print_polygon_info();
}