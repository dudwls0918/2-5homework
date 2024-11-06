#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool checkWinner(const vector<vector<int>>& board, int row, int col, int player);


int main() {
    ifstream inputFile("board.txt");
    int boardSize;
    inputFile >> boardSize;

    vector<vector<int>> board(boardSize, vector<int>(boardSize));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            inputFile >> board[i][j];
        }
    }

    inputFile.close();

    bool blackWins = false;
    bool whiteWins = false;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] != 0) {
                if (checkWinner(board, i, j, board[i][j])) {
                    if (board[i][j] == 1)
                        blackWins = true;
                    else
                        whiteWins = true;
                }
            }
        }
    }

    if (blackWins)
        cout << "Black" << endl;
    else if (whiteWins)
        cout << "White" << endl;
    else
        cout << "Not Finished" << endl;
    return 0;
}

bool checkWinner(const vector<vector<int>>& board, int row, int col, int player) {
    int dx[] = { 1, 0, 1, -1 };
    int dy[] = { 0, 1, 1, 1 };
    for (int k = 0; k < 4; ++k) {
        int cnt = 1;
        for (int d = 1; d < 5; ++d) {
            int r = row + dy[k] * d;
            int c = col + dx[k] * d;
            if (r >= 0 && r < board.size() && c >= 0 && c < board.size() && board[r][c] == player)
                cnt++;
            else
                break;
        }
        for (int d = 1; d < 5; ++d) {
            int r = row - dy[k] * d;
            int c = col - dx[k] * d;
            if (r >= 0 && r < board.size() && c >= 0 && c < board.size() && board[r][c] == player)
                cnt++;
            else
                break;
        }
        if (cnt >= 5)
            return true;
    }
    return false;
}

