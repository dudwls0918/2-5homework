#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    for (int y = 0; y <= 100; y++)
    {
        for (int x = 0; x <= 3 * y; x++)
        {
            if (x >= 3 * (double)y / 2)
            {
                if (x * x + y * y <= 10000)
                    count++;
            }
        }
    }
    cout << count << endl;
    return 0;

}