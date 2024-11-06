#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (words[i].length() > words[j].length())
            {
                swap(words[i], words[j]);
            }
            else if (words[i].length() == words[j].length() && words[i] > words[j])
            {
                swap(words[i], words[j]);
            }
        }
    }

    for (const string& word : words)
    {
        cout << word << endl;
    }

    return 0;
}
