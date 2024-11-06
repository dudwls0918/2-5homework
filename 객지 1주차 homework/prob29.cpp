#include<iostream>
using namespace std;
const int MAX = 100;
int main()
{
	int n;
	cin >> n;
	int data[MAX];
	for (int i = 0; i < n; i++)
		cin >> data[i];

	int k;
	cin >> k;
	
	int current_length = 0;
	int max_length = 0;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += data[j];
			if (sum <= k)
			{
				current_length = j - i + 1;
				if (current_length > max_length)
					max_length = current_length;
			}
			else
				break;
		}

	}
	cout << max_length << endl;
	return 0;
}
