#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "������ �Է��ϼ��� : ";
    cin >> n;

    if (n <= 0)
    {
        cout << "���� ������ �Է��ϼ���." << endl;
        return 1;
    }

    double sum = 0;
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
        sum += 1.0 / fac;
    }

    cout << "���� : " << sum;

    return 0;
}