#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int x = 0, y = 0;
    unordered_set<string> visited;

    while (true) {
        int direction, distance;
        cin >> direction >> distance;

        if (direction == -1 && distance == -1)
            break;

        string move = to_string(x) + "," + to_string(y);

        if (visited.count(move)) {
            cout << "invalid move" << endl;
            continue;
        }

        visited.insert(move);

        switch (direction) {
            case 0: // 상
                y += distance;
                break;
            case 1: // 우
                x += distance;
                break;
            case 2: // 하
                y -= distance;
                break;
            case 3: // 좌
                x -= distance;
                break;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}
