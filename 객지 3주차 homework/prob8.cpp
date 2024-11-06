#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<string> readDictionary(const string& filename) {
    set<string> wordlist;
    ifstream file(filename);
    string word;
    while (file >> word) {
        for (char& c : word) {
            c = tolower(c);
        }
        wordlist.insert(word);
    }
    file.close();
    return wordlist;
}

vector<vector<string>> readPuzzle(const string& filename) {
    vector<vector<string>> grid;
    ifstream file(filename);
    int size;
    file >> size;
    for (int i = 0; i < size; ++i) {
        vector<string> row;
        for (int j = 0; j < size; ++j) {
            string word;
            file >> word;
            for (char& c : word) {
                c = tolower(c);
            }
            row.push_back(word);
        }
        grid.push_back(row);
    }
    file.close();
    return grid;
}

void searchWord(int x, int y, int dx, int dy, const vector<vector<string>>& grid, const set<string>& wordlist, set<string>& wordsFound, string word = "") {
    int rows = grid.size();
    int cols = grid[0].size();
    if (x < 0 || y < 0 || x >= rows || y >= cols) {
        return;
    }
    word += grid[x][y];
    if (wordlist.find(word) != wordlist.end()) {
        wordsFound.insert(word);
    }
    searchWord(x + dx, y + dy, dx, dy, grid, wordlist, wordsFound, word);
}

set<string> searchWords(const vector<vector<string>>& grid, const set<string>& wordlist) {
    int rows = grid.size();
    int cols = grid[0].size();
    set<string> wordsFound;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx != 0 || dy != 0) {
                        searchWord(i, j, dx, dy, grid, wordlist, wordsFound);
                    }
                }
            }
        }
    }
    return wordsFound;
}

int main() {
    string dictionaryFile = "dictionary.txt";
    set<string> wordlist = readDictionary(dictionaryFile);

    string puzzleFile = "puzzle.txt";
    vector<vector<string>> grid = readPuzzle(puzzleFile);

    set<string> wordsFound = searchWords(grid, wordlist);
    for (const string& word : wordsFound) {
        cout << word << endl;
    }

    return 0;
}
