#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "���� �����ϳ��� �Է����ּ���: ";
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