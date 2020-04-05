#include <cmath>
#include "Point.h"

Point::Point() {
    this -> x = 0;
    this -> y = 0;
}

Point::Point(float x, float y) {
    this -> x = x;
    this -> y = y;
}

float Point::angle() {
    return atan2(this -> x, this -> y) * 180.0 / M_PI;
}

float Point::length() {
    return sqrt(this -> x * this -> x + this -> y * this -> y);
}

Point& Point::operator+=(const Point& other) {
    this -> x += other.x;
    this -> y += other.y;
    return *this;
}

Point& Point::operator-=(const Point& other) {
    this -> x -= other.x;
    this -> y -= other.y;
    return *this;
}

Point& Point::operator*=(const float scale) {
    this -> x *= scale;
    this -> y *= scale;
    return *this;
}

Point& Point::operator/=(const float scale) {
    this -> x /= scale;
    this -> y /= scale;
    return *this;
}

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator*(const Point& p, const float scale) {
    return Point(p.x * scale, p.y * scale);
}

Point operator/(const Point& p, const float scale) {
    return Point(p.x / scale, p.y / scale);
}
