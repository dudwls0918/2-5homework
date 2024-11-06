#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main()
{
	string text;
	while (true)
	{
		getline(cin, text);
		if (text == "exit")
			break;

		string newtext;
		bool space = false;
		for (char c : text)
		{

			if (c == ' ')
			{
				if (!space)
				{
					newtext += ' ';
					space = true;

				}

			}
			else
			{
				newtext += c;
				space = false;

			}
			
		}
		cout << newtext << ";" << newtext.length() << endl;

	}
	return 0;
}
