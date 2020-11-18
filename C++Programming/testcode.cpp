#include <iostream>
#include "polygon.h"
using namespace std;

int main ()
{
    int angle = 3;
    C2D *tri = new C2D[angle] {{1,0},{0,0},{0,1}};
    cout << tri[0].x << endl;
    polygon *test = new polygon(angle,tri);
    test->printpolygoninfo();
}