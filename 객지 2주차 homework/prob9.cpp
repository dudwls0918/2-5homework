#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("shuffled_dict.txt");

    vector<string> lines;
    string line;
    while (getline(infile, line))
    {
        lines.push_back(line);
    }
    infile.close();

    
    for (int i = lines.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[j + 1] < lines[j])
            {
                swap(lines[j], lines[j + 1]);
            }
        }
    }

    string word;
    cin >> word;
    
    
    bool found = false;
    bool prefix_found = false;
    vector<string> prefix_matches;

    for (int i = 0; i < lines.size(); i++)
    {
        int length_index = lines[i].find('\t');
        string current_word = lines[i].substr(0, length_index);

        if (current_word == word)
        {
            cout << "Found:" << endl << lines[i] << endl;
            found = true;
        }
        if (current_word == word or current_word.find(word) == 0)
        {
            prefix_matches.push_back(lines[i]);
            prefix_found = true;
        }
    }

    if (!found)
    {
        cout << "Not found" << endl;

       
        for (int i = 0; i < lines.size(); i++)
        {
            int length_index = lines[i].find('\t');
            string current_word = lines[i].substr(0, length_index);

            if (current_word > word)
            {
                if (i > 0)
                {
                    cout << "- 이전 단어: " << lines[i - 1] << endl;
                }
                if (i < lines.size() - 1)
                {
                    cout << "+ 다음 단어: " << lines[i] << endl;
                }
                break;
            }
        }

    }
       
        if (prefix_found)
        {
            cout <<endl<< "Results of prefix search:" << endl;
            for (const auto& match : prefix_matches)
            {
                cout << match << endl;
            }
        }
   
    return 0;
}
