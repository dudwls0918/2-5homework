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
	int current_length = 1;
	int max_length = 1;

	
	for (int i = 1; i < n; ++i)
	{
		if (data[i] >= data[i - 1])
			current_length++;
		if (current_length > max_length)
			max_length = current_length;
		if(data[i] < data[i-1])
			current_length = 1;

	}
	cout << max_length << endl;
	return 0;
}
