#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "100보다 작은 정수 n를 입력해주세요; ";
	cin >> n;
	int number[100] = { 0 };
	
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) 
	{
		int last = number[n - 1];
		for (int j = n - 1; j > 0; --j) 
		{
			number[j] = number[j - 1];
		}
		number[0] = last;
	}
	for (int i = 0; i < n; i++)
	{
		cout << number[i] << " ";
	}

	return 0;

	


}