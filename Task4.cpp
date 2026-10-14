#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int r, int c, int N, const vector<vector<int>>& board) {
    return (r >= 0 && r < N && c >= 0 && c < N && board[r][c] == -1);
}

bool solveKnightTour(int r, int c, int moveCount, int N, vector<vector<int>>& board) {
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int nextR = r + dx[i];
        int nextC = c + dy[i];

        if (isValid(nextR, nextC, N, board)) {
            board[nextR][nextC] = moveCount + 1;

            if (solveKnightTour(nextR, nextC, moveCount + 1, N, board)) {
                return true;
            }

            board[nextR][nextC] = -1;
        }
    }

    return false;
}

void printBoard(const vector<vector<int>>& board, int N) {
    cout << "\nKnight's Tour Found:\n\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(4) << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int N, startR, startC;

    cout << "Enter board size N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid board size.\n";
        return 1;
    }

    cout << "Enter starting position (row col) [0 to " << N - 1 << "]: ";
    cin >> startR >> startC;

    if (startR < 0 || startR >= N || startC < 0 || startC >= N) {
        cout << "Invalid starting position!\n";
        return 1;
    }

    vector<vector<int>> board(N, vector<int>(N, -1));

    board[startR][startC] = 1;

    if (solveKnightTour(startR, startC, 1, N, board)) {
        printBoard(board, N);
    } else {
        cout << "\nNo valid Knight's Tour exists for board size " 
             << N << " x " << N << " starting at (" << startR << ", " << startC << ").\n";
    }

    return 0;
}