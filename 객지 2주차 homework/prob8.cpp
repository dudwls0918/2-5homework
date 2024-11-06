#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words;
   
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
       
    }

    string prefix = words[0];

    for (int i = 1; i < n; ++i)
    {
        int len = min(prefix.length(), words[i].length());
        int j;
        for (j = 0; j < len; ++j)
        {
            if (prefix[j] != words[i][j])
            {
                break;
            }
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }

    if (prefix.empty())
    {
        cout << "nothing" << endl;
    }
    else {
        cout << "가장 긴 공통 접두사: " << prefix << endl;
    }

    return 0;
}

