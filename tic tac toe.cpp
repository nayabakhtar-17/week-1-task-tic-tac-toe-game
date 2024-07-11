#include <iostream>
using namespace std;

class TicTacToe {
private:
    int board[3][3];

public:
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }
    }

    void printBoard() {
        cout << "  0 1 2" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) cout << ".";
                else if (board[i][j] == 1) cout << "X";
                else cout << "O";
                cout << " ";
            }
            cout << endl;
        }
    }

    bool validMove(int x, int y) {
        return (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == 0);
    }

    void makeMove(int player) {
        int x, y;
        while (true) {
            cout << "Player " << player << ", enter your move (row and column): ";
            cin >> x >> y;
            if (validMove(x, y)) {
                board[x][y] = player;
                break;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    int gameStatus() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
                return board[i][0];
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
                return board[0][i];
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
            return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
            return board[0][2];

        // Check for draw
        bool draw = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    draw = false;
                    break;
                }
            }
        }

        if (draw) return 0;

        // Game is still ongoing
        return -1;
    }
};

int main() {
    TicTacToe game;
    int player = 1;
    int status;

    while ((status = game.gameStatus()) == -1) {
        game.printBoard();
        game.makeMove(player);
        player = (player == 1) ? 2 : 1;
    }

    game.printBoard();
    if (status == 0) {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << status << " wins!" << endl;
    }

    return 0;
}

