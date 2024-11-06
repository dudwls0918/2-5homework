#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

struct Point {
    int x, y;
};

bool intersect(const Line& l1, const Line& l2);
bool onSegment(int xi, int yi, int xj, int yj, int xk, int yk);

int main() {
    int N;
    cin >> N;

    vector<Line> lines(N);
    for (int i = 0; i < N; ++i) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2; // 선분의 시작점과 끝점 입력 받기
    }

    vector<Point> intersections;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (intersect(lines[i], lines[j])) {
                // 교차점 계산하여 저장
                int x = max(min(lines[i].x1, lines[i].x2), min(lines[j].x1, lines[j].x2));
                int y = max(min(lines[i].y1, lines[i].y2), min(lines[j].y1, lines[j].y2));
                intersections.push_back({x, y});
            }
        }
    }

    sort(intersections.begin(), intersections.end(), [](const Point& a, const Point& b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });

    for (const auto& intersection : intersections) {
        cout << "[" << intersection.x << ", " << intersection.y << "]" << endl;
    }

    return 0;
}

bool intersect(const Line& l1, const Line& l2) {
    // 두 선분이 서로 평행한지 확인
    if (max(l1.x1, l1.x2) < min(l2.x1, l2.x2) || max(l2.x1, l2.x2) < min(l1.x1, l1.x2) ||
        max(l1.y1, l1.y2) < min(l2.y1, l2.y2) || max(l2.y1, l2.y2) < min(l1.y1, l1.y2)) {
        return false;
    }

    int d1 = (l1.x2 - l1.x1) * (l2.y1 - l1.y1) - (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
    int d2 = (l1.x2 - l1.x1) * (l2.y2 - l1.y1) - (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
    int d3 = (l2.x2 - l2.x1) * (l1.y1 - l2.y1) - (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
    int d4 = (l2.x2 - l2.x1) * (l1.y2 - l2.y1) - (l1.x2 - l2.x1) * (l2.y2 - l2.y1);

    if ((d1 * d2 < 0) && (d3 * d4 < 0))
        return true;
    else
        return false;
}

bool onSegment(int xi, int yi, int xj, int yj, int xk, int yk) {
    return (xj <= max(xi, xk) && xj >= min(xi, xk) &&
            yj <= max(yi, yk) && yj >= min(yi, yk));
}
