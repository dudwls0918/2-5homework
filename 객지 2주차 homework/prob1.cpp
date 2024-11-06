#include <iostream>
#include <vector>
#include<string>
using namespace std;
const int MAX = 100;

int main() {
    int n;

    cin >> n;

    string numbers[MAX];


    for (int i = 0; i < n; i++) {
        string num;
        cin >> numbers[i];
        
        
    }


    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((numbers[j]).compare((numbers[minIndex])) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(numbers[i], numbers[minIndex]);
        }
    }


    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
