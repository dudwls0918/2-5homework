#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "���� n�� �Է�(2 �̻� 30 ����): ";
    cin >> n;

    if (n < 2 || n > 30) {
        cout << "2 �̻� 30 ������ ������ �Է��ؾ���." << endl;
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

    cout << "�Ǻ���ġ ������ " << n << "��° ���� " << result << "�Դϴ�." << endl;

    return 0;
}