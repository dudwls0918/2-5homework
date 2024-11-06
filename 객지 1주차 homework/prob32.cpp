#include <iostream>
using namespace std;
int const MAX = 100;


int main() {
    int n;    cin >> n;

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxOnes = 0, count = 0, lastZeroIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
        } else {
            maxOnes = max(maxOnes, count);
            count = i - lastZeroIndex;
            lastZeroIndex = i;
        }
    }

    maxOnes = max(maxOnes, count);

    cout << maxOnes << endl;

    return 0;
}
