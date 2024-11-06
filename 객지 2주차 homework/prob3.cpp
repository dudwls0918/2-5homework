#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;

int main() {
    string words[MAX];
    int counts[MAX] = { 0 };
    int n = 0;

    ifstream infile("input3.txt");
    string word;
    while (infile >> word)
    {
        
        for (int i = 0; i < word.length(); i++)
            word[i] = tolower(word[i]);

        words[n++] = word;
    }
    infile.close();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (words[i] == words[j]) {
                counts[i]++;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (counts[i] < counts[j] || (counts[i] == counts[j] && words[i] > words[j])) {
                swap(words[i], words[j]);
                swap(counts[i], counts[j]);
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        if (i == 0 || words[i] != words[i - 1]) {
            cout << words[i] << ":" << counts[i] << endl;
        }
    }

    return 0;
}

