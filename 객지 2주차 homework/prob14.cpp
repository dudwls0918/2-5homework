#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("harry.txt");
    vector<string> words;
    string word;
    while (infile >> word)
    {
        string clean_word;
        for (char c : word)
        {
            if (isalnum(c))
            {
                clean_word.push_back(tolower(c));
            }
        }

        bool is_duplicate = false;
        for (const string& w : words)
        {
            if (w == clean_word)
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            words.push_back(clean_word);
        }
    }
    infile.close();

    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t j = i + 1; j < words.size(); j++)
        {
            if (words[i] > words[j])
            {
                swap(words[i], words[j]);
            }
        }
    }

    string prefix;

    cin >> prefix;

    int count = 0;
    for (const auto& w : words)
    {
        if (w.substr(0, prefix.length()) == prefix)
        {
            cout << w << endl;
            count++;
        }
    }
    cout  << count << endl;

    return 0;
}
