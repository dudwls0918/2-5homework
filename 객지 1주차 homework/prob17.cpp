#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n;
	const int MAX = 100;
	cout << "100이하의 정수를 입력해주세요";
	cin >> n;
	int number[MAX] = { 0 };
;

	for (int i = 0; i < n; i++)
		cin >> number[i];
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += number[i];
	double mean = sum / n;

	double v = 0;
	for (int i = 0; i < n; i++)
		v += (number[i] - mean) * (number[i] - mean);
	double d = 0;
	d = sqrt(v / n);

	cout << mean << endl;
	cout << d << endl;

	return 0;


	

}