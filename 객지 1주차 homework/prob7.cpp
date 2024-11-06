#include <iostream>
using namespace std;

int main()
{
	int y1, y2, m1, m2, d1, d2;
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	if ((y1 < y2) or (y1 == y2 && m1 < m2) or (y1 == y2 && m1 == m2 && d1 < d2))
	{
		cout << "-1";
	}
	if ((y1 > y2) or (y1 == y2 && m1 > m2) or (y1 == y2 && m1 == m2 && d1 > d2))
	{
		cout << "1";
	}
	if(y1==y2 && m1==m2 && d1==d2)
	{
		cout << "0";
	}

	return 0;
}