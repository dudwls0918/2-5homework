#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "양의 정수하나를 입력해주세요: ";
	cin >> n;
	int number[10] = { 0 };

	while (n > 0)
	{
		int digit = n % 10;
		number[digit]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << number[i] << ",";

	return 0;




}