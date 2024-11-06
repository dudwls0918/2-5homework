#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

class Point {
private:
    double x, y;
public:
    Point() = default;
    Point(double a, double b) : x(a), y(b) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double distSq(const Point& p) const {
        return (x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY());
    }
};

class Line {
private:
    Point s, t;
public:
    Line() = default;
    Line(const Point& a, const Point& b) : s(a), t(b) {}

    const Point& getStart() const { return s; }
    const Point& getEnd() const { return t; }

    bool isVertical() const {
        return s.getY() == t.getY();
    }
};

class Rect {
private:
    Point lu, rl;
public:
    Rect() = default;
    Rect(const Point& a, const Point& b) : lu(a), rl(b) {}

    const Point& getLU() const { return lu; }
    const Point& getRL() const { return rl; }

    double area() const {
        double width = abs(rl.getX() - lu.getX());
        double height = abs(rl.getY() - lu.getY());
        return width * height;
    }

    bool intersect(const class Circle& circle) const;
};

class Circle {
private:
    Point center;
    double radius;
public:
    Circle() = default;
    Circle(const Point& c, double r) : center(c), radius(r) {}

    const Point& getCenter() const {
        return center;
    }

    double getRadius() const {
        return radius;
    }

    bool contains(const Point& p) const {
        return center.distSq(p) <= radius * radius;
    }

    bool intersect(const Rect& rect) const {
        return rect.intersect(*this);
    }

    bool intersect(const Line& seg) const {
        if (contains(seg.getStart()) || contains(seg.getEnd()))
            return true;
        if (seg.isVertical()) {
            if (seg.getStart().getX() < center.getX() && center.getX() < seg.getEnd().getX() && abs(seg.getStart().getY() - center.getY()) < radius)
                return true;
        }
        else {
            if (seg.getStart().getY() < center.getY() && center.getY() < seg.getEnd().getY() && abs(seg.getStart().getX() - center.getX()) < radius)
                return true;
        }
        return false;
    }

    double intersectArea(const Circle& other) const {
        double d = center.distSq(other.center);
        if (d >= (radius + other.radius) * (radius + other.radius))
            return 0.0;
        if (d <= abs(radius - other.radius) * abs(radius - other.radius))
            return min(M_PI * radius * radius, M_PI * other.radius * other.radius);
        double cosA = (radius * radius + d - other.radius * other.radius) / (2 * radius * sqrt(d));
        double cosB = (other.radius * other.radius + d - radius * radius) / (2 * other.radius * sqrt(d));
        double A = acos(cosA) * radius * radius;
        double B = acos(cosB) * other.radius * other.radius;
        double C = 0.5 * sqrt((-d + radius + other.radius) * (d + radius - other.radius) * (d - radius + other.radius) * (d + radius + other.radius));
        double intersectionArea = A + B - C;
        return intersectionArea;
    }

    bool intersect(const Circle& other) const {
        double d = center.distSq(other.center);
        return d <= (radius + other.radius) * (radius + other.radius);
    }
};

bool Rect::intersect(const Circle& circle) const {
    double circleDistX = abs(circle.getCenter().getX() - (lu.getX() + rl.getX()) / 2);
    double circleDistY = abs(circle.getCenter().getY() - (lu.getY() + rl.getY()) / 2);

    if (circleDistX > (rl.getX() - lu.getX()) / 2 + circle.getRadius()) return false;
    if (circleDistY > (rl.getY() - lu.getY()) / 2 + circle.getRadius()) return false;

    if (circleDistX <= (rl.getX() - lu.getX()) / 2) return true;
    if (circleDistY <= (rl.getY() - lu.getY()) / 2) return true;

    double cornerDistSq = pow(circleDistX - (rl.getX() - lu.getX()) / 2, 2) +
        pow(circleDistY - (rl.getY() - lu.getY()) / 2, 2);

    return cornerDistSq <= pow(circle.getRadius(), 2);
}

int main() {
    ifstream inputFile("input1.txt");
    if (!inputFile.is_open()) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    if (n <= 0) {
        cerr << "도형의 개수가 올바르지 않습니다." << endl;
        inputFile.close();
        return 1;
    }

    vector<pair<double, string>> intersectingShapes;

    
    vector<Rect> rects;
    vector<Circle> circles;
    for (int i = 0; i < n; ++i) {
        char type;
        inputFile >> type;
        if (type == 'R') {
            double x1, y1, x2, y2;
            inputFile >> x1 >> y1 >> x2 >> y2;
            rects.emplace_back(Point(x1, y1), Point(x2, y2));
        }
        else if (type == 'C') {
            double cx, cy, r;
            inputFile >> cx >> cy >> r;
            circles.emplace_back(Point(cx, cy), r);
        }
    }

    
    double cx, cy, r;
    inputFile >> cx >> cy >> r;
    Circle testCircle(Point(cx, cy), r);

    
    for (const auto& rect : rects) {
        if (rect.intersect(testCircle)) {
            double intersectionArea = rect.area();
            intersectingShapes.emplace_back(intersectionArea, "R");
        }
    }
    for (const auto& circle : circles) {
        if (circle.intersect(testCircle)) {
            double intersectionArea = min(M_PI * circle.getRadius() * circle.getRadius(), testCircle.intersectArea(circle));
            intersectingShapes.emplace_back(intersectionArea, "C");
        }
    }

    inputFile.close();

    
    sort(intersectingShapes.begin(), intersectingShapes.end(), greater<>());

    
    for (const auto& shape : intersectingShapes) {
        if (shape.second == "R") {
            cout << "R " << rects.size() << " " << rects[0].getLU().getX() << " " << rects[0].getLU().getY() << " " << rects[0].getRL().getX() << " " << rects[0].getRL().getY() << endl;
        }
        else if (shape.second == "C") {
            cout << "C " << circles[0].getCenter().getX() << " " << circles[0].getCenter().getY() << " " << circles[0].getRadius() << endl;
        }
    }

    return 0;
}












