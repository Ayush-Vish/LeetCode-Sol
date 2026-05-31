#include <bits/stdc++.h>



/***
 * 
 * 
 * Key Patterns used 
 * Stragety for Playere s
 *  
 */

using namespace std;

// ---------------- ENUM ----------------
enum class Symbol { X, O, EMPTY };

// ---------------- POSITION ----------------
class Position {
public:
    int row, col;
    Position(int r, int c) : row(r), col(c) {}
};

// ---------------- BOARD ----------------
class GAmeEventListener  {
public:
    virtual void onMoveMade(const Position &pos, Symbol sym) = 0;
    virtual void onGameEnd(Symbol winner) = 0;
    virtual ~GAmeEventListener() {}
};
class Board {
private:
    int size;
    vector<vector<Symbol>> grid;
    vector<GAmeEventListener*> listeners;

public:
    Board(int n = 3) : size(n), grid(n, vector<Symbol>(n, Symbol::EMPTY)) {}

    bool isValidMove(const Position &pos) const {
        return pos.row >= 0 && pos.row < size &&
               pos.col >= 0 && pos.col < size &&
               grid[pos.row][pos.col] == Symbol::EMPTY;
    }
    void addListener(GAmeEventListener *listener) {
        listeners.push_back(listener);
    }

    void makeMove(const Position &pos, Symbol sym) {
        grid[pos.row][pos.col] = sym;
    }

    Symbol getCell(int r, int c) const {
        return grid[r][c];
    }

    int getSize() const {
        return size;
    }

    void printBoard() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                char c = (grid[i][j] == Symbol::X) ? 'X' :
                         (grid[i][j] == Symbol::O) ? 'O' : '.';
                cout << c;
                if (j < size - 1) cout << " | ";
            }
            cout << "\n";
            if (i < size - 1) cout << "---------\n";
        }
        cout << "\n";
    }

    // -------- GAME STATE CHECK --------
    Symbol checkWinner() const {
        int n = size;

        // Rows & Columns
        for (int i = 0; i < n; i++) {
            if (grid[i][0] != Symbol::EMPTY) {
                bool win = true;
                for (int j = 1; j < n; j++)
                    if (grid[i][j] != grid[i][0]) win = false;
                if (win) return grid[i][0];
            }

            if (grid[0][i] != Symbol::EMPTY) {
                bool win = true;
                for (int j = 1; j < n; j++)
                    if (grid[j][i] != grid[0][i]) win = false;
                if (win) return grid[0][i];
            }
        }

        // Diagonals
        if (grid[0][0] != Symbol::EMPTY) {
            bool win = true;
            for (int i = 1; i < n; i++)
                if (grid[i][i] != grid[0][0]) win = false;
            if (win) return grid[0][0];
        }

        if (grid[0][n - 1] != Symbol::EMPTY) {
            bool win = true;
            for (int i = 1; i < n; i++)
                if (grid[i][n - i - 1] != grid[0][n - 1]) win = false;
            if (win) return grid[0][n - 1];
        }

        return Symbol::EMPTY;
    }

    bool isFull() const {
        for (auto &row : grid)
            for (auto &cell : row)
                if (cell == Symbol::EMPTY) return false;
        return true;
    }
};

// ---------------- STRATEGY ----------------
class PlayerStrategy {
public:
    virtual Position makeMove(const Board &board) = 0;
    virtual ~PlayerStrategy() {}
};

// ---------------- HUMAN STRATEGY ----------------
class HumanStrategy : public PlayerStrategy {
public:
    Position makeMove(const Board &board) override {
        int r, c;
        cout << "Enter row and col: ";
        cin >> r >> c;
        return Position(r, c);
    }
};

// ---------------- AI STRATEGY ----------------
class RandomAIStrategy : public PlayerStrategy {
public:
    Position makeMove(const Board &board) override {
        vector<Position> moves;
        int n = board.getSize();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board.getCell(i, j) == Symbol::EMPTY)
                    moves.emplace_back(i, j);
            }
        }

        if (moves.empty()) return Position(-1, -1);
        return moves[rand() % moves.size()];
    }
};

// ---------------- PLAYER ----------------
class Player {
private:
    Symbol symbol;
    PlayerStrategy *strategy;

public:
    Player(Symbol sym, PlayerStrategy *strat)
        : symbol(sym), strategy(strat) {}

    Position makeMove(const Board &board) {
        return strategy->makeMove(board);
    }

    Symbol getSymbol() const {
        return symbol;
    }
};

// ---------------- GAME ----------------
class TicTacToeGame {
private:
    Board board;
    Player *p1;
    Player *p2;
    Player *currentPlayer;

public:
    TicTacToeGame(Player *player1, Player *player2, int size = 3)
        : board(size), p1(player1), p2(player2), currentPlayer(player1) {}

    void switchPlayer() {
        currentPlayer = (currentPlayer == p1) ? p2 : p1;
    }

    void play() {
        while (true) {
            board.printBoard();

            Position move = currentPlayer->makeMove(board);

            if (!board.isValidMove(move)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board.makeMove(move, currentPlayer->getSymbol());

            Symbol winner = board.checkWinner();
            if (winner != Symbol::EMPTY) {
                board.printBoard();
                cout << (winner == Symbol::X ? "X" : "O") << " wins!\n";
                break;
            }

            if (board.isFull()) {
                board.printBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};





// ---------------- MAIN ----------------
int main() {
    srand(time(0));

    PlayerStrategy *p1Strategy = new HumanStrategy();
    PlayerStrategy *p2Strategy = new RandomAIStrategy(); 

    Player *p1 = new Player(Symbol::X, p1Strategy);
    Player *p2 = new Player(Symbol::O, p2Strategy);

    TicTacToeGame game(p1, p2);
    game.play();

    return 0;
}
