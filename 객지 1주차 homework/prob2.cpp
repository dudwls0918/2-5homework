#include <iostream>
#include<cmath>
using namespace std;


int main() {
	int n;
	cin >> n;
	double a = 0.0;
	double result;
	for (int i = 1; i <= n; i++)
		a += pow(-1, i) / pow(2, i);

	result = 1.0 + a;
	cout << result << endl;
	return 0;


}