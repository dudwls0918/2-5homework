#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int v = 1;
    while (v <= N / 2)
    {
        v *= 2;
    }
    while (v > 0)
    {
        if (N >= v)
        {
            N = N - v;
            cout << 1;
            v = 0.5 * v;
        }
        else
        {
            cout << 0;
            v = 0.5 * v;
        }

    }

    return 0;
}