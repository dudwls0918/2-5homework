#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int count = 0;

    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 0)
                ++count;
            num /= 10;
        }
    }
    cout << count << endl;
    
    return 0;
        

}
