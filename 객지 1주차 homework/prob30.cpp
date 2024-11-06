#include <iostream>

using namespace std;
const int MAX = 100;

int main() {
    int n;
    cout << "구간의 수 입력 : ";
    cin >> n;

    int intervals[MAX][2];
    cout << "구간 입력 :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int maxOverlap = 0;
    int maxOverlappingIntervals[2][2];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int overlap = min(intervals[i][1], intervals[j][1]) - max(intervals[i][0], intervals[j][0]);

            if (overlap > maxOverlap) {
                maxOverlap = overlap;
                maxOverlappingIntervals[0][0] = intervals[i][0];
                maxOverlappingIntervals[0][1] = intervals[i][1];
                maxOverlappingIntervals[1][0] = intervals[j][0];
                maxOverlappingIntervals[1][1] = intervals[j][1];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        cout << "[" << maxOverlappingIntervals[i][0] << ", " << maxOverlappingIntervals[i][1] << "]" << endl;
    }

    return 0;
}
