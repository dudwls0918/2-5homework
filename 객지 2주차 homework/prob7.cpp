#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{
	
	vector<string> words;
	while (true)
	{
		string word;
		cin >> word;
		
		if (word == "exit")
			break;
		
		bool isduplicate = false;
		for (string w : words)
		{
			if (word == w)
			{
				isduplicate = true;
				break;
			}
		}
		if (isduplicate==true)
			cout << "duplicate" << endl;
		else
		{
			words.push_back(word);
			for (int i = words.size() - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (words[j + 1] < words[j])
					{
						swap(words[j], words[j + 1]);
					}
				}
			}
			for (string w : words)
			{
				cout << w << " ";

			}
		}

		cout << endl;
	}

	return 0;
}