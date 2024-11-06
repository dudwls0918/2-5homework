#include <iostream>
using namespace std;

int main() {
    int coef, expo_x, expo_y;
    cin >> coef >> expo_x >> expo_y;

    if (coef == 1 && expo_x == 0 && expo_y == 0) {
        cout << "1";
    }
    else if (coef == -1 && expo_x == 0 && expo_y == 0) {
        cout << "-1";
    }
    else {
        if (coef != 1 && coef != -1) {
            cout << coef;
        }
        else if (coef == -1) {
            cout << "-";
        }

        if (expo_x != 0) {
            cout << "x";
            if (expo_x != 1) {
                cout << "^" << expo_x;
            }
        }

        if (expo_y != 0) {
            if (expo_x != 0) {
                cout << "y";
            }
            else if (coef != 1 && coef != -1) {
                cout << "y";
            }
            else {
                cout << "y";
            }

            if (expo_y != 1) {
                cout << "^" << expo_y;
            }
        }
    }

    cout << endl;
    return 0;
}