#include <iostream>
using namespace std;

int main()
{
    const int size = 7;
    int nums[size];

    cout << "1과 13 사이의 정수 7개 입력: ";
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int straightCount = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (nums[i] + 1 == nums[i + 1])
        {
            straightCount++;
        }
    }

    if (straightCount >= 4)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}
