#include<iostream>
#include<vector>
using namespace std;

void compute_set(vector<int>& A, vector<int>& B)
{	
	for (int i = 0; i < A.size() - 1; i++)
	{
		for (int j = 0; j < B.size() - 1; j++)
		{
			if (A[i] == B[j])
			{
				auto jindex = B.begin();
				auto index = A.begin();
				index += i;
				jindex += j;
				A.erase(index);
				B.erase(jindex);
				
			}
		}
	}
	for (auto n : B)
	{
		A.push_back(n);
	}
	for (int i = A.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int m, n, k;
	vector<int>  first, second;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		first.push_back(k);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		second.push_back(k);
	}

	compute_set(first, second);

	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;

}