#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int n;
	cout << "n<=100인 양의 정수를 입력해주세요: ";
	cin >> n;
	
	int number[100] = { 0 };
	
	for (int i = 0; i < n; i++)
		cin >> number[i];

	
	
	int k;
	cin >> k;
	int min = abs(number[0] - k);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int left;
		left = abs(k - number[i]);
		if (left < min)
		{
			min = left;
			result = number[i];
		}
	}
	cout << result << endl;
	
	return 0;
	

}