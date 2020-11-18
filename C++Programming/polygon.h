#pragma once
struct C2D {
    double x, y; // x축 좌표와 y축 좌표
};
class polygon {
private:
    int number_of_vertices;
    C2D *vertex_coordinates;
public:
    polygon(const int numberofvertices, const C2D *vertexcoordinates);
    polygon(const polygon& polygonobject);
    polygon(polygon&& polygonobject);
    ~polygon();
    bool simple_or_complex() const;
    double area_of_polygon() const;
    void print_polygon_info() const;
    polygon move_polygon(double x, double y) ;
};
