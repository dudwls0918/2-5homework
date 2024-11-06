#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cctype> 
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;
vector<string> lines;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
vector<string> split_line(string line, char delimiter);

int main() {
    string command;
    while (true) {
        cout << "$ ";
        cin >> command;
        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "exit")
            break;
        else if (command == "find") {
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
        else if (command == "find") {
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
           
        
    }
    return 0;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index != -1) {
        cout << "The word income appears" << lineNums[index].size() << " times in lines" << endl;
        for (auto lineNum : lineNums[index])
            cout << lineNum << " : " << lines[lineNum] << endl;

    }
    else
        cout << "The word " << keyword << " doesn¡¯t appear." << endl;
}

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        lines.push_back(line);
        vector<string> tokens = split_line(line, ' ');
        for (auto s : tokens)
            if (s.length() > 0)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}

vector<string> split_line(string line, char delimiter) {
    vector <string> tokens;
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, delimiter)) {
        string pureword;
       
        int s = 0, t = str.length() - 1;
        while (s < str.length() && !isalpha(str[s]))
            s++;
        while (t >= 0 && !isalpha(str[t]))
            t--;
        if (s <= t) {
            pureword = str.substr(s, t - s + 1);
            for (int i = 0; i < pureword.length(); i++)
                pureword[i] = tolower(pureword[i]);
        }
        if(pureword.length()>3)
            tokens.push_back(pureword);
    }
    return tokens;
}

void addWord(string word, int lineNum) {
    int index = findWord(word);
    if (index > -1) {
        if (find(lineNums[index].begin(), lineNums[index].end(), lineNum) == lineNums[index].end())
            lineNums[index].push_back(lineNum);
    }
    else {
        words.push_back(word);
        vector<int> tmp = { lineNum };
        lineNums.push_back(tmp);
    }

    for (int i = words.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (words[j] > words[j + 1]) {
                swap(words[j], words[j + 1]);
                swap(lineNums[j], lineNums[j + 1]);
            }
        }
    }
}

int findWord(string keyword) {
    for (int i = 0; i < words.size(); i++)
        if (words[i] == keyword)
            return i;
    return -1;
}

