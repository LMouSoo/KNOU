#pragma once
struct C2D {
    double x, y; // x축 좌표와 y축 좌표
};
class polygon {
private:
    int numberofvertices;
    C2D *vertexcoordinates;
public:
    polygon(const int numberofvertices, const C2D *vertexcoordinates);
    //polygon();
    ~polygon();
    polygon(const polygon& polygonobject);
    polygon(polygon&& polygonobject);
    double areaofpolygon() const;
    void printpolygoninfo() const;
    polygon movepolygon(double x, double y) ;
};
