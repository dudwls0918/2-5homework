#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 1000;

int main() {
    ifstream file("sample_lines.txt");
    int wordCounts[MAX] = { 0 };
    string lines[MAX];
    int lineCount = 0;

    string line;
    while (getline(file, line)) {
        int wordCount = 0;
        bool inWord = false;
        for (char c : line) {
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                if (inWord) {
                    inWord = false;
                }
            }
            else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }

        if (wordCount == 0)
            continue;

        lines[lineCount] = line;
        wordCounts[lineCount] = wordCount;
        lineCount++;
    }
    file.close();

    for (int i = 0; i < lineCount; ++i) {
        for (int j = i + 1; j < lineCount; ++j) {
            if (wordCounts[i] < wordCounts[j]) {
                int tempWordCount = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = tempWordCount;

                string tempLine = lines[i];
                lines[i] = lines[j];
                lines[j] = tempLine;
            }
        }
    }

    for (int i = 0; i < lineCount; ++i) {
        cout << lines[i] << ": " << wordCounts[i] << endl;
    }

    return 0;
}
