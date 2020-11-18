#include <iostream>
#include "polygon.h"
using namespace std;

int main ()
{
    int inputnumberofvertices;
    double x, y;
    cout << "꼭짓점의 갯수를 정수로 입력하세요" <<endl;
    cin >> inputnumberofvertices;
    C2D *inputvertexcoordinates = new C2D[inputnumberofvertices];
    for(int i = 0; i < inputnumberofvertices; i++){
        cout << i+1 << "번째 꼭짓점의 x좌표 y좌표를 입력하세요." << endl;
        cin >> x >> y;
        inputvertexcoordinates[i] = {x, y};
    }
    polygon poly1(inputnumberofvertices, inputvertexcoordinates);
    poly1.printpolygoninfo();
    polygon test2(poly1);
    test2.printpolygoninfo();
    polygon test3(move(test2));
    //polygon&& test3 = test2.movepolygon(1,1);
    //polygon test4(test3);
    test3.printpolygoninfo();
    test2.printpolygoninfo();
    //polygon *test = new polygon(angle,tri);
    //polygon *test2 = new polygon(test);
}