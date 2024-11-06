#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class MyPoint {
public:
    int x, y;
    MyPoint() = default;
    MyPoint(int a, int b) : x(a), y(b) {}
};

class Circle {
private:
    double pi = 3.14;
    MyPoint P;
    int r;
public:
    Circle() = default;
    Circle(int x, int y, int radius) : P(x, y), r(radius) {}

    MyPoint getCenter() const { return P; }
    int getRadius() const { return r; }

    double area() const {
        return r * r * pi;
    }

    bool C_BY_C_intersect(const Circle& My_Circle) const {
        double deltaX = P.x - My_Circle.P.x;
        double deltaY = P.y - My_Circle.P.y;

        double length = sqrt(deltaX * deltaX + deltaY * deltaY);

        return length <= r + My_Circle.r;
    }
};

class Rect {
private:
    MyPoint lu, rl;
public:
    Rect() = default;
    Rect(int x_min, int x_max, int y_min, int y_max) : lu(x_min, y_min), rl(x_max, y_max) {}

    MyPoint getLU() const { return lu; }
    MyPoint getRL() const { return rl; }

    int area() const {
        return (rl.x - lu.x) * (rl.y - lu.y);
    }

    bool C_BY_R_intersect(const Circle& My_Circle) const {
        int C_X = My_Circle.getCenter().x;
        int C_Y = My_Circle.getCenter().y;
        int C_R = My_Circle.getRadius();

        Rect expand_r(lu.x - C_R, rl.x + C_R, lu.y - C_R, rl.y + C_R); // 확장된 사각형
        if (C_Y > expand_r.lu.y && C_Y < expand_r.rl.y &&
            C_X > expand_r.lu.x && C_X < expand_r.rl.x) {
            return true;
        } // 대각선의 경우 사각형의 꼭짓점과 원의 중점 거리비교
        if (C_X < lu.x && C_Y < lu.y) // 좌상단
            return diagonal_chk(lu.x, lu.y, My_Circle);

        if (C_X > rl.x && C_Y < lu.y) // 우상단
            return diagonal_chk(rl.x, lu.y, My_Circle);

        if (C_X < lu.x && C_Y > rl.y) // 좌하단
            return diagonal_chk(lu.x, rl.y, My_Circle);

        if (C_X > rl.x && C_Y > rl.y) // 우하단
            return diagonal_chk(rl.x, rl.y, My_Circle);

        return false;
    }

    bool diagonal_chk(int x, int y, const Circle& My_Circle) const {
        double DT_X = x - My_Circle.getCenter().x;
        double DT_Y = y - My_Circle.getCenter().y;
        double C_R = My_Circle.getRadius();
        double length = sqrt(DT_X * DT_X + DT_Y * DT_Y);
        return length <= C_R;
    }
};

int main() {
    fstream infile("input1.txt");

    int N;
    infile >> N;
    Circle** C_list = new Circle * [N];
    Rect** R_list = new Rect * [N];

    int C_count = 0, R_count = 0;
    for (int i = 0; i < N; ++i) {
        char str;
        infile >> str;
        if (str == 'R') {
            int x1, x2, y1, y2;
            infile >> x1 >> x2 >> y1 >> y2;
            R_list[R_count++] = new Rect(x1, x2, y1, y2);
        }
        else if (str == 'C') {
            int x, y, r;
            infile >> x >> y >> r;
            C_list[C_count++] = new Circle(x, y, r);
        }
    }

    int my_x, my_y, my_r;
    infile >> my_x >> my_y >> my_r;
    Circle* My_Circle = new Circle(my_x, my_y, my_r);

    infile.close();

    Circle** A_C = new Circle * [C_count];
    Rect** A_R = new Rect * [R_count];
    int A_C_count = 0, A_R_count = 0;

    for (int i = 0; i < C_count; ++i) {
        if (C_list[i]->C_BY_C_intersect(*My_Circle))
            A_C[A_C_count++] = C_list[i];
    }

    for (int i = 0; i < R_count; ++i) {
        if (R_list[i]->C_BY_R_intersect(*My_Circle))
            A_R[A_R_count++] = R_list[i];
    }

    sort(A_C, A_C + A_C_count, [](Circle* a, Circle* b) {
        return a->area() < b->area();
        });

    sort(A_R, A_R + A_R_count, [](Rect* a, Rect* b) {
        return a->area() < b->area();
        });

    int i = 0, j = 0;
    while (i < A_C_count || j < A_R_count) {
        if (i == A_C_count) {
            cout << "R " << A_R[j]->getLU().x << " " << A_R[j]->getRL().x
                << " " << A_R[j]->getLU().y << " " << A_R[j]->getRL().y << endl;
            j++;
        }
        else if (j == ITS_R_count) {
            cout << "C " << A_C[i]->getCenter().x << " " <<
                A_C[i]->getCenter().y << " " << A_C[i]->getRadius() << endl;
            i++;
        }
        else if (A_C[i]->area() < A_R[j]->area()) {
            cout << "C " << A_C[i]->getCenter().x << " " <<
                A_C[i]->getCenter().y << " " << A_C[i]->getRadius() << endl;
            i++;
        }
        else {
            cout << "R " << A_R[j]->getLU().x << " " << A_R[j]->getRL().x
                << " " << A_R[j]->getLU().y << " " << A_R[j]->getRL().y << endl;
            j++;
        }
    }

    delete My_Circle;
    for (int i = 0; i < C_count; ++i) delete C_list[i];
    for (int i = 0; i < R_count; ++i) delete R_list[i];
    delete[] C_list;
    delete[] R_list;
    delete[] A_C;
    delete[] A_R;

    return 0;
}
