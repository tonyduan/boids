#ifndef POINT_H_
#define POINT_H_

class Point {
    
public:
    float x;
    float y;

    Point();
    Point(float x, float y);

    float angle();
    float length();

    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
    Point& operator*=(const float scale);
    Point& operator/=(const float scale);
};
#endif

Point operator+(const Point& p1, const Point& p2);
Point operator-(const Point& p1, const Point& p2);
Point operator*(const Point& p, const float scale);
Point operator/(const Point& p, const float scale);

