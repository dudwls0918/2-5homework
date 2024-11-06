#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    srand((unsigned int)time(NULL));

    int N;
    cout << "배열 크기 N을 입력하세요 (홀수): ";
    cin >> N;

    

    int successCount = 0;
    int experimentCount = 10000;

    for (int exp = 0; exp < experimentCount; ++exp) {
        int x = N / 2, y = N / 2;
        int visited[MAX][MAX] = {0};

        while (x != 0 && x != N - 1 && y != 0 && y != N - 1) {
            int moves = 0;
            for (int i = 0; i < 4; ++i) {
                int nx = x, ny = y;
                if (i == 0 && x > 0 && !visited[x - 1][y]) { nx--; moves++; }
                if (i == 1 && x < N - 1 && !visited[x + 1][y]) { nx++; moves++; }
                if (i == 2 && y > 0 && !visited[x][y - 1]) { ny--; moves++; }
                if (i == 3 && y < N - 1 && !visited[x][y + 1]) { ny++; moves++; }
            }
            if (moves == 0) break;

            int move = rand() % moves;
            for (int i = 0; i < 4; ++i) {
                int nx = x, ny = y;
                if (i == 0 && x > 0 && !visited[x - 1][y]) { nx--; move--; }
                if (i == 1 && x < N - 1 && !visited[x + 1][y]) { nx++; move--; }
                if (i == 2 && y > 0 && !visited[x][y - 1]) { ny--; move--; }
                if (i == 3 && y < N - 1 && !visited[x][y + 1]) { ny++; move--; }
                if (move < 0) { x = nx; y = ny; visited[x][y] = true; break; }
            }
        }
        if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
            successCount++;
    }

    cout << (double)successCount / experimentCount << endl;

    return 0;
}
