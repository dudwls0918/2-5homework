#include<iostream>
using namespace std;

int main()
{	
	
	srand((unsigned int)time(NULL));
	int t = 0;
	int T = 0;
	int Aacount = 0;
	int Bacount = 0;
	while (t < 1000000)
	{
		int win = 0;
		for (int i = 0; i < 6; i++)
		{
			
			if (rand() % 6 + 1 == 1)
				win++;
		}
		if (win >= 1)
			Aacount++;
		t++;
	}	
	
	while(T<1000000)
	{
		int win = 0;
		for(int i =0; i<12; i++)
		{
			
			if (rand() % 6 + 1 == 1)
				win++;
		}
		if (win >= 2)
			Bacount++;
		T++;
	}
	cout << "6번 던졌을때의 경우의수 " << Aacount << endl;
	cout << "12번 던졌을떄의 경우의 수 " << Bacount << endl;

	return 0;
}