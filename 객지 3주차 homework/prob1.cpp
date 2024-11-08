#include<iostream>
#include<string>
#include<vector>
using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second)
{
	for (auto a : second)
	{
		first.push_back(a);
	}
	for (int i = first.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (first[j] > first[j + 1])
			{
				string tmp = first[j];
				first[j] = first[j + 1];
				first[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int m, n;
	string str;
	vector<string>first, second;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		first.push_back(str);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		second.push_back(str);
	}

	sorted_merge(first, second);
	
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}