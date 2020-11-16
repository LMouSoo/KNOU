#pragma once
class polygon {
    int numberofvertices;
    //C2D *vertexcoordinates;
public:
    //polygon(const int numberofvertices, const C2D *vertexcoordinates);
    polygon();
    ~polygon();
    polygon(const polygon& polygonobject);
    double areaofpolygon() const;
    void printpolygoninfo() const;
};
