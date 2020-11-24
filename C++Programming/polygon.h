#pragma once    // polygon.h가 중복 include 되지 않도록 체크 (C++11 이상)
struct C2D {
    double x, y; // x축 좌표와 y축 좌표
};
class polygon {
private:
    int number_of_vertices;                                             // 다각형 꼭짓점 갯수
    C2D *vertex_coordinates;                                            // 다각형 꼭짓점 좌표 저장 포인터
public:
    polygon(const int numberofvertices, const C2D *vertexcoordinates);  // 생성자
    polygon(const polygon& polygonobject);                              // 복사 생성자
    polygon(polygon&& polygonobject);                                   // 이동 생성자
    ~polygon();                                                         // 소멸자
    //bool simple_or_complex() const;    신발끈공식은 simple polygon에서만 사용가능하기때문에 판정함수를 만드려 했으나 보류
    double area_of_polygon() const;                                     // 다각형의 넓이를 반환
    void print_polygon_info() const;                                    // 다각형의 정보를 출력
    void vertex_coordinates_memory_address() const;                     // 다각형 꼭짓점 좌표 저장 포인터 출력
    polygon move_polygon(const double x, const double y);               // 위치를 옮긴 다각형을 반환
};
