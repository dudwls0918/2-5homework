#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "정수를 입력하세요 : ";
    cin >> n;

    if (n <= 0)
    {
        cout << "양의 정수를 입력하세요." << endl;
        return 1;
    }

    double sum = 0;
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
        sum += 1.0 / fac;
    }

    cout << "합은 : " << sum;

    return 0;
}