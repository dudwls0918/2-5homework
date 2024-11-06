#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "정수 n을 입력(2 이상 30 이하): ";
    cin >> n;

    if (n < 2 || n > 30) {
        cout << "2 이상 30 이하의 정수를 입력해야함." << endl;
        return 1;
    }

    int a = 1;
    int b = 1;
    int result = 0;

    for (int i = 2; i <= n; ++i) {
        result = b + a;
        a = b;
        b = result;
    }

    cout << "피보나치 수열의 " << n << "번째 수는 " << result << "입니다." << endl;

    return 0;
}