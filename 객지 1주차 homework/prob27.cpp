#include<iostream>
using namespace std;
const int MAX = 100;
int main()
{
	int n;
	int num[MAX];
	int count=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i ; j < n; j++)
		{
			if (num[i] > num[j])
				count++;
		}
	}

	cout << count << endl;
	return 0;
}

