#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class Rectangle {
private:
    int xmin, xmax, ymin, ymax;

public:
    Rectangle(int x1, int x2, int y1, int y2) : xmin(x1), xmax(x2), ymin(y1), ymax(y2) {}

    int getXMin() const { return xmin; }
    int getXMax() const { return xmax; }
    int getYMin() const { return ymin; }
    int getYMax() const { return ymax; }
};

class MinimumCircle {
private:
    vector<Rectangle> rectangles;
    double centerX, centerY, radius;

public:
    MinimumCircle(const vector<Rectangle>& rects) : rectangles(rects) {}

    // 두 점 사이의 거리를 계산하는 함수
    double distance(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    // 모든 사각형을 포함하는 가장 작은 원을 계산하는 함수
    void computeMinimumCircle() {
        double minX = numeric_limits<double>::infinity();
        double maxX = -numeric_limits<double>::infinity();
        double minY = numeric_limits<double>::infinity();
        double maxY = -numeric_limits<double>::infinity();

        // 사각형들의 경계 좌표를 찾음
        for (const auto& rect : rectangles) {
            minX = min(minX, static_cast<double>(rect.getXMin()));
            maxX = max(maxX, static_cast<double>(rect.getXMax()));
            minY = min(minY, static_cast<double>(rect.getYMin()));
            maxY = max(maxY, static_cast<double>(rect.getYMax()));
        }


        // 원의 중심을 계산
        centerX = (minX + maxX) / 2;
        centerY = (minY + maxY) / 2;

        // 반지름 계산
        radius = max({ distance(centerX, centerY, minX, minY),
                      distance(centerX, centerY, minX, maxY),
                      distance(centerX, centerY, maxX, minY),
                      distance(centerX, centerY, maxX, maxY) });
    }

    // 결과를 출력하는 함수
    void printResult() {
        cout << "중점 좌표: (" << centerX << ", " << centerY << ")" << endl;
        cout << "반지름: " << radius << endl;
    }
};

// 입력 파일로부터 사각형 정보를 읽어들이는 함수
vector<Rectangle> readRectangles(const string& filename) {
    vector<Rectangle> rectangles;
    ifstream file(filename);
    if (file.is_open()) {
        int n;
        file >> n;
        for (int i = 0; i < n; ++i) {
            int x1, x2, y1, y2;
            file >> x1 >> x2 >> y1 >> y2;
            rectangles.emplace_back(x1, x2, y1, y2);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return rectangles;
}

// 메인 함수
int main() {
    string filename = "input2.txt";
    vector<Rectangle> rectangles = readRectangles(filename);
    MinimumCircle mc(rectangles);
    mc.computeMinimumCircle();
    mc.printResult();
    return 0;
}



