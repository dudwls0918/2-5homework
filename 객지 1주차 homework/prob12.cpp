#include <iostream>

using namespace std;

int main()
{
    int num, prev_num, next_num;
    int count = 0;

    cout << "정수를 입력하세요 (-1 입력 시 종료): ";

    cin >> prev_num;

    while (true)
    {
        cin >> num;

        if (num == -1)
        {
            break;
        }
        cin >> next_num;

        if (prev_num <= num && (next_num == -1 || num <= next_num))
        {
            count++;
        }
        prev_num = num;
    }

    cout << "극소값의 개수: " << count << endl;

    return 0;
}
